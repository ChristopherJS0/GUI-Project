using namespace System;
using namespace System::Windows::Forms;
#include "AllClasses.h"
//Christopher Salinas-Sanchez

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