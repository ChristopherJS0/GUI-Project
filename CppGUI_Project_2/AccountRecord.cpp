using namespace System;
using namespace System::Windows::Forms;
#include "AllClasses.h"

//Christopher Salinas

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