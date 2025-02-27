using namespace System::IO;
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Text;
using namespace System::Threading;
#include "AllClasses.h"

//Christopher Salinas-Sanchez

//For network.
const int ClientPORT = 1234;
const int StayAlive = 10;

Client::Client()
{
	ClientState = 0; //Client state is at PIN

	client = gcnew TcpClient();
	client->Connect(IPAddress::Parse("127.0.0.1"), ClientPORT);
	NetStream = client->GetStream();
	NetStream->ReadTimeout = 20000; //Stream should wait 20 seconds for a command BEFORE shutting down stream!
	
	//This sends to the servers stream and server constructor should check if it says this to accept the connection.
	array<Byte>^ sendBytes = Encoding::ASCII->GetBytes("CONNECT");
	NetStream->Write(sendBytes, 0, sendBytes->Length);

	//Sleep to give server time to send its message
	Thread::Sleep(200);
	array<Byte>^ RecieveBytes = gcnew array<Byte>(1024);

	//Recieving server's incoming bytes. Infiinite loop to keep checking if server sent msg or not.
	while (true)
	{
		int ReadBytes = NetStream->Read(RecieveBytes, 0, RecieveBytes->Length);

		String^ ACK_Connected = Encoding::ASCII->GetString(RecieveBytes, 0, ReadBytes);
		if (ACK_Connected == "CONNECTED") //Expects that line ACK 00, 00 represents the first state AND constructor.
		{
			//Client and server are connected!
			Console::WriteLine("ACK recieved!");
			break;
		}
	}
}

void Client::SendAcctNum(int PassedAcct)
{
	String^ AcctString = PassedAcct.ToString();
	String^ S_AcctPass = "0A" + AcctString; //The 0A represents State and which button pressed.
	Console::WriteLine(S_AcctPass);

	array<Byte>^ SendThis = Encoding::UTF8->GetBytes(S_AcctPass);
	// Send the bytes over the network stream
	NetStream->Write(SendThis, 0, SendThis->Length);
	
	//bytes that will be recieved and read as an ACK.
	array<Byte>^ receiveBytes = gcnew array<Byte>(1024);

		//Give time to Server.
		Thread::Sleep(100);

		//Preparing for bytes to read.
		int BytesConvert = NetStream->Read(receiveBytes, 0, receiveBytes->Length);
		String^ ACK = Encoding::ASCII->GetString(receiveBytes, 0, BytesConvert);

		//Must accept a certain ACK.
		if (ACK == "ACK0A") {
			Console::WriteLine("ACK0A Recieved!");
		}
		//If more than a 3 second passed.
		else  { ClientClose(); }
	
}
void Client::SendPinNum(int PassedPin)
{
	String^ StringChange = PassedPin.ToString();
	String^ ToBytes = "1A" + StringChange; //The 1A represents State and which button pressed.

	array<Byte>^ SendThis = Encoding::UTF8->GetBytes(ToBytes);
	// Send the bytes over the network stream
	NetStream->Write(SendThis, 0, SendThis->Length);

	//bytes that will be recieved and read as an ACK.
	array<Byte>^ receiveBytes = gcnew array<Byte>(1024);

	//I'll have a TickCounter to get to a certain point that it will shut down client
	//if not ACKed in time.
	int TickCounter = 0;
	while (true)
	{
		//Give time to Server.
		Thread::Sleep(100);

		//Preparing for bytes to read.
		int BytesConvert = NetStream->Read(receiveBytes, 0, receiveBytes->Length);
		String^ ACK = Encoding::ASCII->GetString(receiveBytes, 0, BytesConvert);

		//Must accept a certain ACK.
		if (ACK == "ACK1A") {
			Console::WriteLine("ACK1A Recieved!");
			break;
		}
		//If more than a 3 second passed.
		else if (TickCounter >= 30) { ClientClose(); }
		TickCounter++;
	}
}

void Client::GoToCheckings()
{
	String^ ToBytes = "2ACheckings"; //represents State and which button pressed.

	array<Byte>^ SendThis = Encoding::UTF8->GetBytes(ToBytes);
	// Send the bytes over the network stream
	NetStream->Write(SendThis, 0, SendThis->Length);

	//bytes that will be recieved and read as an ACK.
	array<Byte>^ receiveBytes = gcnew array<Byte>(1024);

	//I'll have a TickCounter to get to a certain point that it will shut down client
	//if not ACKed in time.
	int TickCounter = 0;
	while (true)
	{
		//Give time to Server.
		Thread::Sleep(100);

		//Preparing for bytes to read.
		int BytesConvert = NetStream->Read(receiveBytes, 0, receiveBytes->Length);
		String^ ACK = Encoding::ASCII->GetString(receiveBytes, 0, BytesConvert);

		//Must accept a certain ACK.
		if (ACK == "ACK2A") {
			Console::WriteLine("ACK2A Recieved!");
			break;
		}
		//If more than a 3 second passed.
		else if (TickCounter >= 30) { ClientClose(); }
		TickCounter++;
	}
}
void Client::GoToSavings()
{
	String^ ToBytes = "2BSavings"; //represents State and which button pressed.

	array<Byte>^ SendThis = Encoding::UTF8->GetBytes(ToBytes);
	// Send the bytes over the network stream
	NetStream->Write(SendThis, 0, SendThis->Length);

	//bytes that will be recieved and read as an ACK.
	array<Byte>^ receiveBytes = gcnew array<Byte>(1024);

	//I'll have a TickCounter to get to a certain point that it will shut down client
	//if not ACKed in time.
	int TickCounter = 0;
	while (true)
	{
		//Give time to Server.
		Thread::Sleep(100);

		//Preparing for bytes to read.
		int BytesConvert = NetStream->Read(receiveBytes, 0, receiveBytes->Length);
		String^ ACK = Encoding::ASCII->GetString(receiveBytes, 0, BytesConvert);

		//Must accept a certain ACK.
		if (ACK == "ACK2B") {
			Console::WriteLine("ACK2B Recieved!");
			break;
		}
		//If more than a 3 second passed.
		else if (TickCounter >= 30) { ClientClose(); }
		TickCounter++;
	}
}

//For me: Remember, don't make the ATM go back after a deposit/withdraw
void Client::DepositThis(double DepAmt)
{
	String^ StringChange = DepAmt.ToString();
	String^ ToBytes = "3B" + StringChange; // represents State and which button pressed.

	array<Byte>^ SendThis = Encoding::UTF8->GetBytes(ToBytes);
	// Send the bytes over the network stream
	NetStream->Write(SendThis, 0, SendThis->Length);

	//bytes that will be recieved and read as an ACK.
	array<Byte>^ receiveBytes = gcnew array<Byte>(1024);

	//I'll have a TickCounter to get to a certain point that it will shut down client
	//if not ACKed in time.
	int TickCounter = 0;
	while (true)
	{
		//Give time to Server.
		Thread::Sleep(100);

		//Preparing for bytes to read.
		int BytesConvert = NetStream->Read(receiveBytes, 0, receiveBytes->Length);
		String^ ACK = Encoding::ASCII->GetString(receiveBytes, 0, BytesConvert);

		//Must accept a certain ACK.
		if (ACK == "ACK3B") {
			Console::WriteLine("ACK3B Recieved!");
			break;
		}
		//If more than a 3 second passed.
		else if (TickCounter >= 30) { ClientClose(); }
		TickCounter++;
	}
}
void Client::WithdrawThis(double WDAmt)
{
	String^ StringChange = WDAmt.ToString();
	String^ ToBytes = "3A" + StringChange; //The 1A represents State and which button pressed.

	array<Byte>^ SendThis = Encoding::UTF8->GetBytes(ToBytes);
	// Send the bytes over the network stream
	NetStream->Write(SendThis, 0, SendThis->Length);

	//bytes that will be recieved and read as an ACK.
	array<Byte>^ receiveBytes = gcnew array<Byte>(1024);

	//I'll have a TickCounter to get to a certain point that it will shut down client
	//if not ACKed in time.
	int TickCounter = 0;
	while (true)
	{
		//Give time to Server.
		Thread::Sleep(100);

		//Preparing for bytes to read.
		int BytesConvert = NetStream->Read(receiveBytes, 0, receiveBytes->Length);
		String^ ACK = Encoding::ASCII->GetString(receiveBytes, 0, BytesConvert);

		//Must accept a certain ACK.
		if (ACK == "ACK3A") {
			Console::WriteLine("ACK3A Recieved!");
			break;
		}
		//If more than a 3 second passed.
		else if (TickCounter >= 30) { ClientClose(); }
		TickCounter++;
	}
}

//Go back when Cancel buttons hit.
void Client::GoBackReq(int State)
{
	//Request server to go back and send a string which details how to.
	if (State == 1)
	{
		String^ ToBytes = "2CStart"; // represents State and which button pressed.

		array<Byte>^ SendThis = Encoding::UTF8->GetBytes(ToBytes);
		// Send the bytes over the network stream
		NetStream->Write(SendThis, 0, SendThis->Length);

		//bytes that will be recieved and read as an ACK.
		array<Byte>^ receiveBytes = gcnew array<Byte>(1024);

		//I'll have a TickCounter to get to a certain point that it will shut down client
		//if not ACKed in time.
		int TickCounter = 0;
		while (true)
		{
			//Give time to Server.
			Thread::Sleep(100);

			//Preparing for bytes to read.
			int BytesConvert = NetStream->Read(receiveBytes, 0, receiveBytes->Length);
			String^ ACK = Encoding::ASCII->GetString(receiveBytes, 0, BytesConvert);

			//Must accept a certain ACK.
			if (ACK == "ACK2C") {
				Console::WriteLine("ACK2C Recieved!");
				break;
			}
			//If more than a 3 second passed.
			else if (TickCounter >= 30) { ClientClose(); }
			TickCounter++;
		}
	}
	else if (State == 2)
	{
		String^ ToBytes = "3CAcctCheck"; // represents State and which button pressed.

		array<Byte>^ SendThis = Encoding::UTF8->GetBytes(ToBytes);
		// Send the bytes over the network stream
		NetStream->Write(SendThis, 0, SendThis->Length);

		//bytes that will be recieved and read as an ACK.
		array<Byte>^ receiveBytes = gcnew array<Byte>(1024);

		//I'll have a TickCounter to get to a certain point that it will shut down client
		//if not ACKed in time.
		int TickCounter = 0;
		while (true)
		{
			//Give time to Server.
			Thread::Sleep(100);

			//Preparing for bytes to read.
			int BytesConvert = NetStream->Read(receiveBytes, 0, receiveBytes->Length);
			String^ ACK = Encoding::ASCII->GetString(receiveBytes, 0, BytesConvert);

			//Must accept a certain ACK.
			if (ACK == "ACK3C") {
				Console::WriteLine("ACK3C Recieved!");
				break;
			}
			//If more than 3 second passed.
			else if (TickCounter >= 30) { ClientClose(); }
			TickCounter++;
		}
	}
}

//Shuts down Client.
void Client::ClientClose()
{
	client->Close();
	NetStream->Close();
}

void Client::CloseCliAndSer()
{
	array<Byte>^ sendBytes = Encoding::ASCII->GetBytes("0CDisconnect");
	NetStream->Write(sendBytes, 0, sendBytes->Length);
	Console::WriteLine("Sending close statement!");

	//Sleep to give server time to send its message
	array<Byte>^ recieveBytes = gcnew array<Byte>(1024);
	int TickCounter = 0;

	while (true)
	{
		//Give time to Server.
		Thread::Sleep(100);

		Console::WriteLine("Waiting for ACK0C");
		//Preparing for bytes to read.
		int BytesConvert = NetStream->Read(recieveBytes, 0, recieveBytes->Length);
		String^ ACK = Encoding::ASCII->GetString(recieveBytes, 0, BytesConvert);

		//Must accept a certain ACK.
		if (ACK == "ACK0C") {
			Console::WriteLine("ACK0C Recieved!");
			break;
		}
		//If more than a 3 second passed.
		else if (TickCounter >= 30) { ClientClose(); }
		TickCounter++;
	}
	client->Close();
	NetStream->Close();
}