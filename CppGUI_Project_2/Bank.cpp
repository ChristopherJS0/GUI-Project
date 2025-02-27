using namespace System;
using namespace System::Windows::Forms;
#include "AllClasses.h"

//Christopher Salinas

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