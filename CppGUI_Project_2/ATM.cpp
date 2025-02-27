using namespace System;
using namespace System::Windows::Forms;
#include "AllClasses.h"

//Christopher Salinas

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
        Console::WriteLine("ATMSTATE is in Account mode");
        if (ActType == AccountType::Checkings) {
            Console::WriteLine("In checkings mode!");
            currentAccount = currentCustomer->getCheckingAccnt();
            //Do changes to UI
            ATMState = State::Transaction; //NEXT STAGE!
            return;
        }
        else if (ActType == AccountType::Savings) {
            Console::WriteLine("In savings mode!");
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
            Console::WriteLine("Withdrawing this " + System::Convert::ToString(GetBalance()));
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
    Console::WriteLine("Called balance get");
    return currentAccount->GetBalance();

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