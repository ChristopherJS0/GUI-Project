using namespace System;
using namespace System::Windows::Forms;
#include "AllClasses.h"
//Christopher Salinas

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
            Console::WriteLine("Found the balance!");
            return Copy->getBalance();
        }
    }
    //If the accNum has no correlating number, it will return -1.
    Console::WriteLine("Returning -1: BankData getBalance has a problem");
    
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