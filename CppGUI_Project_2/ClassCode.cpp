#include "Classes.h"
using namespace System;
using namespace System::Windows::Forms;


//Christopher Salinas-Sanchez
// File Summary: Here is where all method definitions will be found,
//this is also where the most coding will be.


//1: CustomerRecord Class Methods
CustomerRecord::CustomerRecord(int CNum, int InPin, int InCheck, int inSav)
{
    CustNumber = CNum; pin = InPin; checkings = InCheck; savings = inSav;
}
int CustomerRecord::getCustNumber()
{
    return CustNumber;
}
int CustomerRecord::getpin()
{
    return pin;
}
int CustomerRecord::getCheckings()
{
    return checkings;
}
int CustomerRecord::getSavings()
{
    return savings;
}

//2: AccountRecord Class Methods
AccountRecord::AccountRecord(int AcctNum)
{
    //The acct num should be equal to the accnt num of the CustomerRecord checkings/savings int.
    AccountNum = AcctNum;
    CurrentBalance = 100.00; //Every account will start with 100 dollars.
}
double AccountRecord::getBalance()
{
    return CurrentBalance;
}
void AccountRecord::SetBalance(double NewAmt)
{
    CurrentBalance = NewAmt;
}
int AccountRecord::getNumber()
{
    return AccountNum;
}


//3: BankData Class Methods
void BankData::Init(array<AccountRecord^>^ PassedAccntRec, array<CustomerRecord^>^ PassedCustRec)
{
    custRecords = gcnew array<CustomerRecord^>(PassedCustRec->Length);
    accntRecords = gcnew array<AccountRecord^>(PassedAccntRec->Length);
    custRecords = PassedCustRec;
    accntRecords = PassedAccntRec;
}
double BankData::GetBalance(int accNum)
{
    //To do
    for (int i = 0; i < accntRecords->Length; i++)
    {
        AccountRecord^ Copy = accntRecords[i];
        if (Copy->getNumber() == accNum)
        {
            return Copy->getBalance();
        }
    }
    //If the accNum has no correlating number, it will return -1.
    return -1.0;
}
void BankData::SetBalance(int accNum, double amount)
{
    for (int i = 0; i < accntRecords->Length; i++)
    {
        AccountRecord^ Copy = accntRecords[i];
        if (Copy->getNumber() == accNum)
        {
            Copy->SetBalance(amount);
        }
    }
}
array<CustomerRecord^>^ BankData::GetCustRecords()
{
    return custRecords;
}
array<AccountRecord^>^ BankData::GetAccntRecords()
{
    return accntRecords;
}


//4: BankAccount Class Methods
BankAccount::BankAccount(int AcctNumInput, BankData^ PassedBankData)
{
    AccountNum = AcctNumInput;
    MyBankData = PassedBankData;
    CurrentBalance = PassedBankData->GetBalance(AcctNumInput);
}
void BankAccount::Deposit(double D_Amount)
{
    CurrentBalance = CurrentBalance + D_Amount;
    StoreBalance(CurrentBalance);
} 
void BankAccount::Withdraw(double W_Amount)
{
    //To Do
    if (W_Amount > CurrentBalance)
    {
        //Cannot allow any change to make it negative, as you shouldn't have a negative bank account.
        return;
    }
    else
    {
        CurrentBalance = CurrentBalance - W_Amount;
        StoreBalance(CurrentBalance);
    }
} 
double BankAccount::GetBalance()
{
    return CurrentBalance;
}
int BankAccount::GetNumber()
{
    return AccountNum;
}
void BankAccount::StoreBalance(double NewAmt)
{
    // This method stores the balance that is CurrentBalance into the MyBankData handle's info.
    CurrentBalance = NewAmt;
    MyBankData->SetBalance(AccountNum, NewAmt);
} 


//5: Customer Class Methods
Customer::Customer(int CustNum, BankData^ MyBankData)
{
    
    array<CustomerRecord^>^ CopyCustRecArr = MyBankData->GetCustRecords();
    array<AccountRecord^>^ CopyAccntRecArr = MyBankData->GetAccntRecords();
    
    //Loop to find customer number
    for (int i = 0; i < CopyCustRecArr->Length; i++)
    {
        CustomerRecord^ CopyCust = CopyCustRecArr[i];
        if (CopyCust->getCustNumber() == CustNum)
        {
            //Customer number found!!
            custNumber = CustNum;
            CheckingsAccnt = gcnew BankAccount(CopyCust->getCheckings(), MyBankData);
            SavingsAccnt = gcnew BankAccount(CopyCust->getSavings(), MyBankData);
        }
    }
    
} 
BankAccount^ Customer::getSavingsAccnt()
{
    return SavingsAccnt;
}
BankAccount^ Customer::getCheckingAccnt()
{
    return CheckingsAccnt;
}
int Customer::GetCustNumber() {return custNumber;}


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
}

//7: Bank Class Methods
Bank::Bank(array<CustomerRecord^>^ PassedCustRecArr, array<AccountRecord^>^ PassedAcntRecArr)
{
    CustRecArray = gcnew array<CustomerRecord^>(PassedCustRecArr->Length);
    AccntRecArray = gcnew array<AccountRecord^>(PassedAcntRecArr->Length);
    CustRecArray = PassedCustRecArr;
    AccntRecArray = PassedAcntRecArr;

    // Initialize the arrays of BankData class by calling its Init() method
    AllBankData = gcnew BankData;
    AllBankData->Init(AccntRecArray, CustRecArray); //This will pass the banks info into the BankData object.

    //This for loop will create customers and insert the objects into a customer array.
    CustomerArr = gcnew array<Customer^>(CustRecArray->Length);
    for (int i = 0; i < CustRecArray->Length; i++)
    {
        CustomerRecord^ CopyCustRec = CustRecArray[i];
        CustomerArr[i] = gcnew Customer(CopyCustRec->getCustNumber(), AllBankData);
    }
}


//8: ATM Class Methods
ATM::ATM(BankInterface^ PassedBankInter)
{
    theBank = PassedBankInter;
    ATMState = State::Start;
}
void ATM::Reset()
{
    ATMState = State::Start;
    
}
void ATM::SetCustomerNumber(int number)
{
    if (ATMState == State::Start)
    {
        customerNumber = number;
        //Perform GUI changes...
        ATMState = State::Pin; //NEXT STAGE!
        return;
    }
    else { return; }
}
void ATM::SelectCustomer(int pin)
{
    if (ATMState == State::Pin)
    {
        //This should crash if something wrong is entered.
        currentCustomer = theBank->FindCustomer(customerNumber, pin);
        customerPin = pin;
        //Perform GUI changes...
        ATMState = State::Account; //NEXT STAGE!
        return;
    }
    else { return; }
}

void ATM::SelectAccnt(AccountType ActType)
{
    //Somehow, this must find out if the passed accnt is C or S.
    if (ATMState == State::Account)
    {
        if (ActType == AccountType::Checkings) {
            currentAccount = currentCustomer->getCheckingAccnt();
            //Do changes to UI
            ATMState = State::Transaction; //NEXT STAGE!
            return;
        }
        else if (ActType == AccountType::Savings) {
            currentAccount = currentCustomer->getSavingsAccnt();
            //Do changes to UI
            ATMState = State::Transaction; //NEXT STAGE!
            return;		
        }
    }
    else { return; }
}
void ATM::Withdraw(double WD_Value)
{
    if (ATMState == State::Transaction)
    {
        //Check to see if the transaction is even possible.

        //Not enough to withdraw! No change will be made.
        //Transaction shouldn't go back to any previous modes unless a button is hit.
        if (GetBalance() < WD_Value){return;}
        else
        {
            double NewBalance = GetBalance() - WD_Value;
            Console::WriteLine(System::Convert::ToString(NewBalance)); //Testing
            currentAccount->StoreBalance(NewBalance);
            Console::WriteLine(System::Convert::ToString(GetBalance()));
            //Changes to UI 
            //Transaction shouldn't go back to any previous modes unless a button is hit.
            return;
        }
    }
    else { return; }
}
void ATM::Deposit(double D_Value)
{
    if (ATMState == State::Transaction)
    {
        double NewBalance = GetBalance() + D_Value;
        Console::WriteLine(System::Convert::ToString(NewBalance)); //Testing
        currentAccount->StoreBalance(NewBalance);
        Console::WriteLine(System::Convert::ToString(GetBalance()));
        //Changes to UI. - TODO
        //Transaction mode still same...
    }
    else { return; }
}
double ATM::GetBalance()
{
    if (ATMState == State::Transaction)
    {
        return currentAccount->GetBalance();
    }
    //-1 will be returned if the ATMState isn't in Transaction mode.
    //This of course should be avoided so it shouldn't happen but because this
    //function must return something, I'll return -1 if it fails.
    else { return -1; }

}
void ATM::back()
{
    switch(ATMState)
    {
    case State::Start:
        break;
    case State::Pin:
        ATMState = State::Start;
        //Do changes to UI.
        break;
    case State::Account:
        ATMState = State::Pin;
        //Do changes to UI.
        break;
    case State::Transaction:
        ATMState = State::Account;
        //Do changes to UI.
        break;
    }
}
int ATM::GetState()
{
    switch (ATMState) {
    case State::Start:
        return 0;
        break;

    case State::Pin:
        return 1;
        break;

    case State::Account:
        return 2;
        break;

    case State::Transaction:
        return 3;
        break;
    }
}
void ATM::CloseAll()
{
     // ACTS AS A DESTRUCTOR. Frees resources used - closes files, databases sockets etc.
     // Because the garbage collector can dispose of the memory used alone, I won't need to call delete.
    Application::Exit();
}