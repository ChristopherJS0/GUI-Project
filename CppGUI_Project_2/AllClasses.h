#pragma once
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::IO;
using namespace System::Text;

public ref class AccountRecord 
{
	//Account record could be for checkings or savings acct.
public:
	AccountRecord(int AcctNum); //Initializes the 2 priv members. 
	double getBalance(); 
	void SetBalance(double NewAmt); 
	int getNumber(); 
private:
	int AccountNum;
	double CurrentBalance = 100;
};
public ref class CustomerRecord 
{
public:
	CustomerRecord(int CNum, int InPin, int InCheck, int inSav); //Creates the 4 data members. TO-DO IN "Placehold.cpp"

	//Returns the data members.
	int getCustNumber(); 
	int getpin(); 
	int getCheckings(); 
	int getSavings(); 

private:
	int CustNumber;
	int pin;
	int checkings; //The checkings account number
	int savings; //The savings acct number
};
public ref class BankData 
{
public:
	void Init(array<AccountRecord^>^ PassedAccntRec, array<CustomerRecord^>^ PassedCustRec);
	double GetBalance(int accNum);
	void SetBalance(int accNum, double amount);
	
	array<AccountRecord^>^ GetAccntRecords();
	array<CustomerRecord^>^ GetCustRecords();

private:
	array<CustomerRecord^>^ custRecords; //Array that will hold customer records.
	array<AccountRecord^>^ accntRecords; //Array that will hold account records of customers.
};
public ref class BankAccount
{
public:
	BankAccount(int AcctNumInput, BankData^ PassedBankData);
	void Deposit(double D_Amount);
	void Withdraw(double W_Amount);
	double GetBalance();
	int GetNumber();
	void StoreBalance(double NewAmt); //Stores the current balance into the BankData's currentBalance member.


private:
	int AccountNum;
	double CurrentBalance;
	BankData^ MyBankData;
};
public ref class Customer
{
public:
	Customer(int CustNum, BankData^ MyBankData);
	BankAccount^ getCheckingAccnt();
	BankAccount^ getSavingsAccnt();
	int GetCustNumber();

private:
	int custNumber;
	BankAccount^ CheckingsAccnt;
	BankAccount^ SavingsAccnt;
};
public interface class BankInterface
{
	Customer^ FindCustomer(int CustNum, int pin);
};
public ref class Bank : public BankInterface
{
public:
	Bank(array<CustomerRecord^>^ PassedCustRecArr, array<AccountRecord^>^ PassedAcntRecArr);
	virtual Customer^ FindCustomer(int CustNum, int pin);
	

private:
	array<CustomerRecord^>^ CustRecArray;
	//Extra to make this work...
	array<AccountRecord^>^ AccntRecArray;
	BankData^ AllBankData;
	array<Customer^>^ CustomerArr;
};
public ref class ATM
{
private:
	//New atm variables	

	int customerPin;

	enum class Transaction
	{
		Deposit = 0,
		Withdraw = 1,
	}Transaction_Type;

	double transactionAmount;
	
	int customerNumber;
	Customer^ currentCustomer;
	BankAccount^ currentAccount;
	BankInterface^ theBank;

public:
	
	enum class State
	{
		Start = 0,
		Pin = 1,
		Account = 2,
		Transaction = 3,
	}ATMState;
	//Had to make public...
	enum class AccountType
	{
		Checkings = 0,
		Savings = 1,
	}AC_Type;

	ATM(BankInterface^ PassedBankInter);
	void Reset(); //Resetting the ATM to the intial state.
	void SetCustomerNumber(int number); 
	void SelectCustomer(int pin); 
	void SelectAccnt(AccountType ActType);
	void Withdraw(double WD_Value);
	void Deposit(double D_Value);
	double GetBalance();
	void back();
	int GetState();
	void CloseAll(); 
};
public ref class Server
{
public:
	Server();
	void ACK(String^ PassedString);
	String^ ACKString(String^ PassedString);
	String^ RepStreamRead();

private:
	int ServerState;
	TcpListener^ listener; 
	TcpClient^ Serclient;
	NetworkStream^ stream;
	String^ SavedString;
	array<Byte>^ receiveBytes;

};
public ref class Client
{
public:

	Client();

	void SendAcctNum(int PassedAcct);
	void SendPinNum(int PassedPin);

	void GoToSavings();
	void GoToCheckings();

	void GoBackReq(int State);

	void WithdrawThis(double WDAmt);
	void DepositThis(double DepAmt);

	void ClientClose();
	void CloseCliAndSer();

private:
	
	//Make sure to check the state of the ATM, save here
	int ClientState;
	TcpClient^ client;
	NetworkStream^ NetStream;

};