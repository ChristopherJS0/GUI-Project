#include "AllClasses.h"
#include "Form1.h"

using namespace System;
using namespace CppGUIProject2;

void Form1::State0Paths()
{
	//Switch cases don't like initializing these sooo done out here.
	//Account Number init
	try
	{
		String^ AccntNumString = SerString->Substring(2);
		int AccntNum = Int32::Parse(AccntNumString);
		GUIATM->SetCustomerNumber(AccntNum);

		//UI Changes
		StateTB->Text = "Pin";
		textBox1->Text = "Recieved: " + SerString;
		textBox2->Text = "Enter Pin and press OK.";
		AcctNumTB->Text = AccntNumString;

	}
	catch (FormatException^)
	{
		StateTB->Text = "Exit";
		textBox2->Text = "Closing...";
		Close();
	}
}
void Form1::State1Paths()
{
	//In state 1, only the pin btn can be hit.
	String^ PinString = SerString->Substring(2);
	int Pin = Int32::Parse(PinString);
	GUIATM->SelectCustomer(Pin);

	PinNumberTB->Text = PinString;
	StateTB->Text = "Account Type";
	textBox1->Text = "Recieved: " + SerString;
	textBox2->Text = "Select Account";
	
}
void Form1::State2Paths()
{
	try
	{	
		if (SerString[1] == 'A') {
			ATM::AccountType Check = ATM::AccountType::Checkings;
			GUIATM->SelectAccnt(Check);
			double CurBalance = GUIATM->GetBalance();
			String^ BalanceStr = CurBalance.ToString();


			textBox1->Text = "Recieved: " + SerString;
			textBox2->Text = "Balance = " + BalanceStr + 
				"\n Enter amount and select transaction.";
			AcctTypeTB->Text = "Checkings";

		}
		else if (SerString[1] == 'B')
		{
			ATM::AccountType Save = ATM::AccountType::Savings;
			GUIATM->SelectAccnt(Save);
			double CurBalance = GUIATM->GetBalance();
			String^ BalanceStr = CurBalance.ToString();


			textBox1->Text = "Recieved: " + SerString;
			textBox2->Text = "Balance = " + BalanceStr +
				"\n Enter amount and select transaction.";
			AcctTypeTB->Text = "Savings";
		}
		else
		{
			textBox1->Text = SerString;
			textBox2->Text = "Enter customer number and press OK.";	
			GUIATM->ATMState = ATM::State::Start;

			StateTB->Text = "Start";
			AcctNumTB->Text = "";
			PinNumberTB->Text = "";
			AcctTypeTB->Text = "";
			TransTypeTB->Text = "";
			TransactionTB->Text = "";
		}
	}
	catch (FormatException^)
	{
		Console::WriteLine("Incorrect information entered: No accnt info");
	}
	
}
void Form1::State3Paths()
{
	try
	{
		if (SerString[1] == 'A') {

			String^ WithDrawStr = SerString->Substring(2);
			double WithDrawAmt = Double::Parse(WithDrawStr);
			GUIATM->Withdraw(WithDrawAmt);

			double CurBalance = GUIATM->GetBalance();
			String^ BalanceStr = CurBalance.ToString();

			StateTB->Text = "Transaction";
			textBox1->Text = "Recieved: " + SerString;
			textBox2->Text = "Balance = " + BalanceStr +
				"\n Enter amount and select transaction.";
			TransTypeTB->Text = "Withdrawal";
			TransactionTB->Text = WithDrawStr;
		}
		else if (SerString[1] == 'B')
		{
			String^ DepositStr = SerString->Substring(2);
			double DepositAmt = Double::Parse(DepositStr);
			GUIATM->Deposit(DepositAmt);


			double CurBalance = GUIATM->GetBalance();
			String^ BalanceStr = CurBalance.ToString();

			StateTB->Text = "Transaction";
			textBox1->Text = "Recieved: " + SerString;
			textBox2->Text = "Balance = " + BalanceStr +
				"\n Enter amount and select transaction.";
			TransTypeTB->Text = "Deposit";
			TransactionTB->Text = DepositStr;
		}
		else
		{
			textBox1->Text = SerString;
			textBox2->Text = "Select Account";
			GUIATM->back();

			StateTB->Text = "Account Type";
			textBox1->Text = "Recieved: " + SerString;
			textBox2->Text = "Select Account";
			AcctTypeTB->Text = "";
			TransTypeTB->Text = "";
			TransactionTB->Text = "";
		}
	}
	catch (FormatException^)
	{
		Console::WriteLine("Incorrect information entered: No accnt info");
	}
}
void Form1::CheckServer()
{
	String^ StreamString = FormServer->RepStreamRead();
	if (SerString == StreamString)
	{
		return;
	}
	
	switch (StreamString[0])
	{
	case '0': 
		SerString = StreamString;
		State0Paths();
		break;

	case '1':
		SerString = StreamString;
		State1Paths();
		break;

	case '2':
		SerString = StreamString;
		State2Paths();
		break;

	case '3':
		SerString = StreamString;
		State3Paths();
		break;
	}

}