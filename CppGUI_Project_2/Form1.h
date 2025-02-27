#pragma once
#include "AllClasses.h"

//Christopher Salinas

namespace CppGUIProject2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	private:
		ATM^ GUIATM;
		Server^ FormServer;
		String^ SerString;
	private: System::Windows::Forms::Timer^ timer1;
	private: void State0Paths();
	private: void State1Paths();
	private: void State2Paths();
	private: void State3Paths();
	private: void CheckServer();
	public:

		Form1(void)
		{
			InitializeComponent();
			FormServer = gcnew Server();

			array<CustomerRecord^>^ ToPassCR_Arr = gcnew array<CustomerRecord^>{
				gcnew CustomerRecord(101, 101, 111, 221), gcnew CustomerRecord(102, 201, 112, 222),
					gcnew CustomerRecord(103, 301, 113, 223), gcnew CustomerRecord(104, 401, 114, 224),
					gcnew CustomerRecord(105, 501, 115, 225)};

			array<AccountRecord^>^ ToPassAR_Arr = gcnew array<AccountRecord^>{
				//Pairs for each of the customers since they have checkings and savings.
				gcnew AccountRecord(111),
					gcnew AccountRecord(221),

					gcnew AccountRecord(112),
					gcnew AccountRecord(222),

					gcnew AccountRecord(113),
					gcnew AccountRecord(223),

					gcnew AccountRecord(114),
					gcnew AccountRecord(224),

					gcnew AccountRecord(115),
					gcnew AccountRecord(225) };
			Bank^ BigBank = gcnew Bank(ToPassCR_Arr, ToPassAR_Arr);
			BankInterface^ BankInter = BigBank;

			GUIATM = gcnew ATM(BankInter);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ AcctTypeTB;
	protected:
	private: System::Windows::Forms::Label^ AcctTypeLabel;
	private: System::Windows::Forms::TextBox^ TransTypeTB;
	private: System::Windows::Forms::Label^ TransTypeLabel;
	private: System::Windows::Forms::TextBox^ TransactionTB;
	private: System::Windows::Forms::Label^ TransactionLabel;
	private: System::Windows::Forms::TextBox^ StateTB;
	private: System::Windows::Forms::Label^ StateLabel;
	private: System::Windows::Forms::TextBox^ PinNumberTB;
	private: System::Windows::Forms::Label^ PinNumLabel;
	private: System::Windows::Forms::TextBox^ AcctNumTB;
	private: System::Windows::Forms::Label^ AcctNumberLabel;



	private: System::Windows::Forms::TextBox^ textBox2;



	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->AcctTypeTB = (gcnew System::Windows::Forms::TextBox());
			this->AcctTypeLabel = (gcnew System::Windows::Forms::Label());
			this->TransTypeTB = (gcnew System::Windows::Forms::TextBox());
			this->TransTypeLabel = (gcnew System::Windows::Forms::Label());
			this->TransactionTB = (gcnew System::Windows::Forms::TextBox());
			this->TransactionLabel = (gcnew System::Windows::Forms::Label());
			this->StateTB = (gcnew System::Windows::Forms::TextBox());
			this->StateLabel = (gcnew System::Windows::Forms::Label());
			this->PinNumberTB = (gcnew System::Windows::Forms::TextBox());
			this->PinNumLabel = (gcnew System::Windows::Forms::Label());
			this->AcctNumTB = (gcnew System::Windows::Forms::TextBox());
			this->AcctNumberLabel = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// AcctTypeTB
			// 
			this->AcctTypeTB->Location = System::Drawing::Point(160, 208);
			this->AcctTypeTB->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->AcctTypeTB->Name = L"AcctTypeTB";
			this->AcctTypeTB->ReadOnly = true;
			this->AcctTypeTB->Size = System::Drawing::Size(169, 22);
			this->AcctTypeTB->TabIndex = 57;
			// 
			// AcctTypeLabel
			// 
			this->AcctTypeLabel->AutoSize = true;
			this->AcctTypeLabel->Location = System::Drawing::Point(50, 208);
			this->AcctTypeLabel->Name = L"AcctTypeLabel";
			this->AcctTypeLabel->Size = System::Drawing::Size(93, 16);
			this->AcctTypeLabel->TabIndex = 56;
			this->AcctTypeLabel->Text = L"Account Type:";
			// 
			// TransTypeTB
			// 
			this->TransTypeTB->Location = System::Drawing::Point(175, 237);
			this->TransTypeTB->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->TransTypeTB->Name = L"TransTypeTB";
			this->TransTypeTB->ReadOnly = true;
			this->TransTypeTB->Size = System::Drawing::Size(154, 22);
			this->TransTypeTB->TabIndex = 55;
			// 
			// TransTypeLabel
			// 
			this->TransTypeLabel->AutoSize = true;
			this->TransTypeLabel->Location = System::Drawing::Point(50, 240);
			this->TransTypeLabel->Name = L"TransTypeLabel";
			this->TransTypeLabel->Size = System::Drawing::Size(116, 16);
			this->TransTypeLabel->TabIndex = 54;
			this->TransTypeLabel->Text = L"Transaction Type:";
			// 
			// TransactionTB
			// 
			this->TransactionTB->Location = System::Drawing::Point(141, 268);
			this->TransactionTB->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->TransactionTB->Name = L"TransactionTB";
			this->TransactionTB->ReadOnly = true;
			this->TransactionTB->Size = System::Drawing::Size(188, 22);
			this->TransactionTB->TabIndex = 53;
			// 
			// TransactionLabel
			// 
			this->TransactionLabel->AutoSize = true;
			this->TransactionLabel->Location = System::Drawing::Point(50, 268);
			this->TransactionLabel->Name = L"TransactionLabel";
			this->TransactionLabel->Size = System::Drawing::Size(81, 16);
			this->TransactionLabel->TabIndex = 52;
			this->TransactionLabel->Text = L"Transaction:";
			// 
			// StateTB
			// 
			this->StateTB->Location = System::Drawing::Point(160, 128);
			this->StateTB->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->StateTB->Name = L"StateTB";
			this->StateTB->ReadOnly = true;
			this->StateTB->Size = System::Drawing::Size(169, 22);
			this->StateTB->TabIndex = 51;
			this->StateTB->Text = L"Start";
			// 
			// StateLabel
			// 
			this->StateLabel->AutoSize = true;
			this->StateLabel->Location = System::Drawing::Point(52, 129);
			this->StateLabel->Name = L"StateLabel";
			this->StateLabel->Size = System::Drawing::Size(41, 16);
			this->StateLabel->TabIndex = 50;
			this->StateLabel->Text = L"State:";
			// 
			// PinNumberTB
			// 
			this->PinNumberTB->Location = System::Drawing::Point(160, 180);
			this->PinNumberTB->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->PinNumberTB->Name = L"PinNumberTB";
			this->PinNumberTB->ReadOnly = true;
			this->PinNumberTB->Size = System::Drawing::Size(169, 22);
			this->PinNumberTB->TabIndex = 49;
			// 
			// PinNumLabel
			// 
			this->PinNumLabel->AutoSize = true;
			this->PinNumLabel->Location = System::Drawing::Point(52, 180);
			this->PinNumLabel->Name = L"PinNumLabel";
			this->PinNumLabel->Size = System::Drawing::Size(80, 16);
			this->PinNumLabel->TabIndex = 48;
			this->PinNumLabel->Text = L"Pin Number:";
			// 
			// AcctNumTB
			// 
			this->AcctNumTB->Location = System::Drawing::Point(160, 155);
			this->AcctNumTB->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->AcctNumTB->Name = L"AcctNumTB";
			this->AcctNumTB->ReadOnly = true;
			this->AcctNumTB->Size = System::Drawing::Size(169, 22);
			this->AcctNumTB->TabIndex = 47;
			// 
			// AcctNumberLabel
			// 
			this->AcctNumberLabel->AutoSize = true;
			this->AcctNumberLabel->Location = System::Drawing::Point(52, 155);
			this->AcctNumberLabel->Name = L"AcctNumberLabel";
			this->AcctNumberLabel->Size = System::Drawing::Size(90, 16);
			this->AcctNumberLabel->TabIndex = 46;
			this->AcctNumberLabel->Text = L"Acct. Number:";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(80, 53);
			this->textBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(249, 53);
			this->textBox2->TabIndex = 42;
			this->textBox2->Text = L"Enter customer number and press OK.";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(102, 11);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(192, 22);
			this->textBox1->TabIndex = 29;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 500;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(412, 327);
			this->Controls->Add(this->AcctTypeTB);
			this->Controls->Add(this->AcctTypeLabel);
			this->Controls->Add(this->TransTypeTB);
			this->Controls->Add(this->TransTypeLabel);
			this->Controls->Add(this->TransactionTB);
			this->Controls->Add(this->TransactionLabel);
			this->Controls->Add(this->StateTB);
			this->Controls->Add(this->StateLabel);
			this->Controls->Add(this->PinNumberTB);
			this->Controls->Add(this->PinNumLabel);
			this->Controls->Add(this->AcctNumTB);
			this->Controls->Add(this->AcctNumberLabel);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	Console::WriteLine("TimerTick!");
	CheckServer();
}
};
};