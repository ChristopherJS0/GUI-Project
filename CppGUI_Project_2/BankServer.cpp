using namespace System::IO;
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Text;
using namespace System::Threading;
#include "AllClasses.h"

//Christopher Salinas-Sanchez

const int PORT = 1234; //1234 will be the port for our server/client.

//6: BankInterface Methods INTO Bank class
Customer^ Bank::FindCustomer(int CustNum, int pin)
{
    //This method should find a customer with the same customer number and matching pin.
    CustomerRecord^ CopyCustRec;
    for (int i = 0; i < CustRecArray->Length; i++)
    {
        CopyCustRec = CustRecArray[i];
        //Testing lines...
        Console::WriteLine(System::Convert::ToString(CopyCustRec->getCustNumber()) + " " + System::Convert::ToString(CopyCustRec->getpin()));
        
        //After getting both the acct num and pin correct, then it'll look for the customer object.
        if (CopyCustRec->getCustNumber() == CustNum && CopyCustRec->getpin() == pin) 
        {
            Console::WriteLine("CustNum and Pin found!");
            for (int j = 0; j < CustomerArr->Length; j++)
            {
                Customer^ CopyCust = CustomerArr[j];
                if (CopyCust->GetCustNumber() == CustNum)
                {
                    Console::WriteLine("We found customer and returned.");
                    return CopyCust;                   
                }
            }
        }
        else { Console::WriteLine("Nothing found..."); }
    }
    //If the loop finishes, then the user never gave valid accnt and pin number
    Console::WriteLine("Information entered was incorrect...");
}

//Different paths for the button presses.
String^ Server::ACKString(String^ StreamString)
{
    String^ StateBtn = StreamString->Substring(0,2);
    String^ SendACK = "ACK" + StateBtn;
    return SendACK;
}

//Choosing a Path method: This is called to process the first state options of clicks A,B, or C
void Server::ACK(String^ PassedString)
{
    SavedString = PassedString;
    String^ ACK = ACKString(PassedString);
    Console::WriteLine(ACK);

    array<Byte>^ ACKbytes = Encoding::ASCII->GetBytes(ACK);

    // get the network stream and send the data
    stream = Serclient->GetStream();
    stream->Write(ACKbytes, 0, ACKbytes->Length);

}

String^ Server::RepStreamRead()
{
    if (stream->DataAvailable) //When you hit exit on the first, this throws an exception...
    {
        //stream = Serclient->GetStream();
        int bytesRead = stream->Read(receiveBytes, 0, receiveBytes->Length);
        String^ receiveString = Encoding::ASCII->GetString(receiveBytes, 0, bytesRead);
        Console::WriteLine("Recieved " + receiveString);

        if (SavedString == receiveString)
        {
            //Do nothing because it doesn't need to repeat what it's done.
            return SavedString;
        }
        else if (receiveString == "0CDisconnect")
        {
            SavedString = receiveString;
            array<Byte>^ sendBytes = Encoding::ASCII->GetBytes("ACK0C");
            Console::WriteLine("Sending ACK0C");
            stream->Write(sendBytes, 0, sendBytes->Length);
            listener->Stop(); Serclient->Close(); stream->Close();
            return SavedString;
        }
        else {
            SavedString = receiveString;
            //The form should keep checking for updates on this
            Console::WriteLine("Sending an ACK for " + receiveString);
            ACK(receiveString);
            return SavedString;
        }
    }
    else
    {
        return SavedString;
    }
    
        
}

//Server functions to help ATM
Server::Server()
{
    SavedString = "Started";
    listener = gcnew TcpListener(IPAddress::Any, PORT);
    listener->Start();
    Console::WriteLine("Server is awaiting a client!");
    Serclient = listener->AcceptTcpClient();
    Console::WriteLine("Client connected");

    bool Close = false;

    // Get client stream and keep the connection open
    stream = Serclient->GetStream();
    receiveBytes = gcnew array<Byte>(1024);

    // Creating an array that will hold what the client sends as bytes
    Thread::Sleep(500);

    try {
        int bytesRead = stream->Read(receiveBytes, 0, receiveBytes->Length);
        String^ receiveString = Encoding::ASCII->GetString(receiveBytes, 0, bytesRead);
        Console::WriteLine("Message received: {0}", receiveString);

        if (receiveString == "CONNECT")
        {
            //Send ACK that it is connected.
            array<Byte>^ sendBytes = Encoding::ASCII->GetBytes("CONNECTED");
            stream->Write(sendBytes, 0, sendBytes->Length);
        }
    }
    catch (IOException^) {
        //If client was never created.
        Console::WriteLine("Client disconnected");
    }
}