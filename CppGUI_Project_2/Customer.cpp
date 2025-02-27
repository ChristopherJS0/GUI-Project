using namespace System;
using namespace System::Windows::Forms;
#include "AllClasses.h"

//Christopher Salinas

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
    // Doesn't protect against incorrect login information.
    return SavingsAccnt;
}
BankAccount^ Customer::getCheckingAccnt()
{
    if (CheckingsAccnt == nullptr)
    {
        Console::WriteLine("Empty Account!");
        return CheckingsAccnt;
    }
    else
    {
        Console::WriteLine("Not empty");
        return CheckingsAccnt;
    }
    
}
int Customer::GetCustNumber() {return custNumber;}