using namespace System;
using namespace System::Windows::Forms;
#include "AllClasses.h"
//Christopher Salinas-Sanchez

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