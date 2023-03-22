#pragma once


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
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			//The first num in the constructors is ACCNT NUMBER, and the second num is PIN NUMBER!!!
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
	private: System::Windows::Forms::Button^ btnC;
	private: System::Windows::Forms::Button^ btnB;
	private: System::Windows::Forms::Button^ btnA;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ btnCE;
	private: System::Windows::Forms::Button^ btnDot;
	private: System::Windows::Forms::Button^ btn0;
	private: System::Windows::Forms::Button^ btn9;
	private: System::Windows::Forms::Button^ btn8;
	private: System::Windows::Forms::Button^ btn7;
	private: System::Windows::Forms::Button^ btn6;
	private: System::Windows::Forms::Button^ btn5;
	private: System::Windows::Forms::Button^ btn4;
	private: System::Windows::Forms::Button^ btn3;
	private: System::Windows::Forms::Button^ btn2;
	private: System::Windows::Forms::Button^ btn1;
	private: System::Windows::Forms::TextBox^ textBox1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
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
			this->btnC = (gcnew System::Windows::Forms::Button());
			this->btnB = (gcnew System::Windows::Forms::Button());
			this->btnA = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->btnCE = (gcnew System::Windows::Forms::Button());
			this->btnDot = (gcnew System::Windows::Forms::Button());
			this->btn0 = (gcnew System::Windows::Forms::Button());
			this->btn9 = (gcnew System::Windows::Forms::Button());
			this->btn8 = (gcnew System::Windows::Forms::Button());
			this->btn7 = (gcnew System::Windows::Forms::Button());
			this->btn6 = (gcnew System::Windows::Forms::Button());
			this->btn5 = (gcnew System::Windows::Forms::Button());
			this->btn4 = (gcnew System::Windows::Forms::Button());
			this->btn3 = (gcnew System::Windows::Forms::Button());
			this->btn2 = (gcnew System::Windows::Forms::Button());
			this->btn1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// AcctTypeTB
			// 
			this->AcctTypeTB->Location = System::Drawing::Point(166, 530);
			this->AcctTypeTB->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->AcctTypeTB->Name = L"AcctTypeTB";
			this->AcctTypeTB->ReadOnly = true;
			this->AcctTypeTB->Size = System::Drawing::Size(190, 26);
			this->AcctTypeTB->TabIndex = 57;
			// 
			// AcctTypeLabel
			// 
			this->AcctTypeLabel->AutoSize = true;
			this->AcctTypeLabel->Location = System::Drawing::Point(43, 530);
			this->AcctTypeLabel->Name = L"AcctTypeLabel";
			this->AcctTypeLabel->Size = System::Drawing::Size(116, 20);
			this->AcctTypeLabel->TabIndex = 56;
			this->AcctTypeLabel->Text = L"Account Type:";
			// 
			// TransTypeTB
			// 
			this->TransTypeTB->Location = System::Drawing::Point(183, 566);
			this->TransTypeTB->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->TransTypeTB->Name = L"TransTypeTB";
			this->TransTypeTB->ReadOnly = true;
			this->TransTypeTB->Size = System::Drawing::Size(173, 26);
			this->TransTypeTB->TabIndex = 55;
			// 
			// TransTypeLabel
			// 
			this->TransTypeLabel->AutoSize = true;
			this->TransTypeLabel->Location = System::Drawing::Point(43, 570);
			this->TransTypeLabel->Name = L"TransTypeLabel";
			this->TransTypeLabel->Size = System::Drawing::Size(143, 20);
			this->TransTypeLabel->TabIndex = 54;
			this->TransTypeLabel->Text = L"Transaction Type:";
			// 
			// TransactionTB
			// 
			this->TransactionTB->Location = System::Drawing::Point(145, 605);
			this->TransactionTB->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->TransactionTB->Name = L"TransactionTB";
			this->TransactionTB->ReadOnly = true;
			this->TransactionTB->Size = System::Drawing::Size(211, 26);
			this->TransactionTB->TabIndex = 53;
			// 
			// TransactionLabel
			// 
			this->TransactionLabel->AutoSize = true;
			this->TransactionLabel->Location = System::Drawing::Point(43, 605);
			this->TransactionLabel->Name = L"TransactionLabel";
			this->TransactionLabel->Size = System::Drawing::Size(102, 20);
			this->TransactionLabel->TabIndex = 52;
			this->TransactionLabel->Text = L"Transaction:";
			// 
			// StateTB
			// 
			this->StateTB->Location = System::Drawing::Point(166, 430);
			this->StateTB->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->StateTB->Name = L"StateTB";
			this->StateTB->ReadOnly = true;
			this->StateTB->Size = System::Drawing::Size(190, 26);
			this->StateTB->TabIndex = 51;
			this->StateTB->Text = L"Start";
			// 
			// StateLabel
			// 
			this->StateLabel->AutoSize = true;
			this->StateLabel->Location = System::Drawing::Point(45, 431);
			this->StateLabel->Name = L"StateLabel";
			this->StateLabel->Size = System::Drawing::Size(53, 20);
			this->StateLabel->TabIndex = 50;
			this->StateLabel->Text = L"State:";
			// 
			// PinNumberTB
			// 
			this->PinNumberTB->Location = System::Drawing::Point(166, 495);
			this->PinNumberTB->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->PinNumberTB->Name = L"PinNumberTB";
			this->PinNumberTB->ReadOnly = true;
			this->PinNumberTB->Size = System::Drawing::Size(190, 26);
			this->PinNumberTB->TabIndex = 49;
			// 
			// PinNumLabel
			// 
			this->PinNumLabel->AutoSize = true;
			this->PinNumLabel->Location = System::Drawing::Point(45, 495);
			this->PinNumLabel->Name = L"PinNumLabel";
			this->PinNumLabel->Size = System::Drawing::Size(102, 20);
			this->PinNumLabel->TabIndex = 48;
			this->PinNumLabel->Text = L"Pin Number:";
			// 
			// AcctNumTB
			// 
			this->AcctNumTB->Location = System::Drawing::Point(166, 464);
			this->AcctNumTB->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->AcctNumTB->Name = L"AcctNumTB";
			this->AcctNumTB->ReadOnly = true;
			this->AcctNumTB->Size = System::Drawing::Size(190, 26);
			this->AcctNumTB->TabIndex = 47;
			// 
			// AcctNumberLabel
			// 
			this->AcctNumberLabel->AutoSize = true;
			this->AcctNumberLabel->Location = System::Drawing::Point(45, 464);
			this->AcctNumberLabel->Name = L"AcctNumberLabel";
			this->AcctNumberLabel->Size = System::Drawing::Size(116, 20);
			this->AcctNumberLabel->TabIndex = 46;
			this->AcctNumberLabel->Text = L"Acct. Number:";
			// 
			// btnC
			// 
			this->btnC->Location = System::Drawing::Point(166, 345);
			this->btnC->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnC->Name = L"btnC";
			this->btnC->Size = System::Drawing::Size(123, 36);
			this->btnC->TabIndex = 45;
			this->btnC->Text = L"Exit";
			this->btnC->UseVisualStyleBackColor = true;
			this->btnC->Click += gcnew System::EventHandler(this, &Form1::btnC_Click);
			// 
			// btnB
			// 
			this->btnB->Location = System::Drawing::Point(166, 304);
			this->btnB->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnB->Name = L"btnB";
			this->btnB->Size = System::Drawing::Size(123, 36);
			this->btnB->TabIndex = 44;
			this->btnB->UseVisualStyleBackColor = true;
			this->btnB->Click += gcnew System::EventHandler(this, &Form1::btnB_Click);
			// 
			// btnA
			// 
			this->btnA->Location = System::Drawing::Point(166, 262);
			this->btnA->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnA->Name = L"btnA";
			this->btnA->Size = System::Drawing::Size(123, 36);
			this->btnA->TabIndex = 43;
			this->btnA->Text = L"OK";
			this->btnA->UseVisualStyleBackColor = true;
			this->btnA->Click += gcnew System::EventHandler(this, &Form1::btnA_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(94, 191);
			this->textBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(280, 65);
			this->textBox2->TabIndex = 42;
			this->textBox2->Text = L"Enter customer number and press OK.";
			// 
			// btnCE
			// 
			this->btnCE->Location = System::Drawing::Point(266, 154);
			this->btnCE->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnCE->Name = L"btnCE";
			this->btnCE->Size = System::Drawing::Size(68, 30);
			this->btnCE->TabIndex = 41;
			this->btnCE->Text = L"CE";
			this->btnCE->UseVisualStyleBackColor = true;
			this->btnCE->Click += gcnew System::EventHandler(this, &Form1::btnCE_Click);
			// 
			// btnDot
			// 
			this->btnDot->Location = System::Drawing::Point(192, 154);
			this->btnDot->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnDot->Name = L"btnDot";
			this->btnDot->Size = System::Drawing::Size(68, 30);
			this->btnDot->TabIndex = 40;
			this->btnDot->Text = L".";
			this->btnDot->UseVisualStyleBackColor = true;
			this->btnDot->Click += gcnew System::EventHandler(this, &Form1::btnDot_Click);
			// 
			// btn0
			// 
			this->btn0->Location = System::Drawing::Point(118, 154);
			this->btn0->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn0->Name = L"btn0";
			this->btn0->Size = System::Drawing::Size(68, 30);
			this->btn0->TabIndex = 39;
			this->btn0->Text = L"0";
			this->btn0->UseVisualStyleBackColor = true;
			this->btn0->Click += gcnew System::EventHandler(this, &Form1::btn0_Click);
			// 
			// btn9
			// 
			this->btn9->Location = System::Drawing::Point(266, 118);
			this->btn9->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn9->Name = L"btn9";
			this->btn9->Size = System::Drawing::Size(68, 30);
			this->btn9->TabIndex = 38;
			this->btn9->Text = L"9";
			this->btn9->UseVisualStyleBackColor = true;
			this->btn9->Click += gcnew System::EventHandler(this, &Form1::btn9_Click);
			// 
			// btn8
			// 
			this->btn8->Location = System::Drawing::Point(192, 118);
			this->btn8->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn8->Name = L"btn8";
			this->btn8->Size = System::Drawing::Size(68, 30);
			this->btn8->TabIndex = 37;
			this->btn8->Text = L"8";
			this->btn8->UseVisualStyleBackColor = true;
			this->btn8->Click += gcnew System::EventHandler(this, &Form1::btn8_Click);
			// 
			// btn7
			// 
			this->btn7->Location = System::Drawing::Point(118, 118);
			this->btn7->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn7->Name = L"btn7";
			this->btn7->Size = System::Drawing::Size(68, 30);
			this->btn7->TabIndex = 36;
			this->btn7->Text = L"7";
			this->btn7->UseVisualStyleBackColor = true;
			this->btn7->Click += gcnew System::EventHandler(this, &Form1::btn7_Click);
			// 
			// btn6
			// 
			this->btn6->Location = System::Drawing::Point(266, 82);
			this->btn6->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn6->Name = L"btn6";
			this->btn6->Size = System::Drawing::Size(68, 30);
			this->btn6->TabIndex = 35;
			this->btn6->Text = L"6";
			this->btn6->UseVisualStyleBackColor = true;
			this->btn6->Click += gcnew System::EventHandler(this, &Form1::btn6_Click);
			// 
			// btn5
			// 
			this->btn5->Location = System::Drawing::Point(192, 82);
			this->btn5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn5->Name = L"btn5";
			this->btn5->Size = System::Drawing::Size(68, 30);
			this->btn5->TabIndex = 34;
			this->btn5->Text = L"5";
			this->btn5->UseVisualStyleBackColor = true;
			this->btn5->Click += gcnew System::EventHandler(this, &Form1::btn5_Click);
			// 
			// btn4
			// 
			this->btn4->Location = System::Drawing::Point(118, 82);
			this->btn4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn4->Name = L"btn4";
			this->btn4->Size = System::Drawing::Size(68, 30);
			this->btn4->TabIndex = 33;
			this->btn4->Text = L"4";
			this->btn4->UseVisualStyleBackColor = true;
			this->btn4->Click += gcnew System::EventHandler(this, &Form1::btn4_Click);
			// 
			// btn3
			// 
			this->btn3->Location = System::Drawing::Point(266, 46);
			this->btn3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn3->Name = L"btn3";
			this->btn3->Size = System::Drawing::Size(68, 30);
			this->btn3->TabIndex = 32;
			this->btn3->Text = L"3";
			this->btn3->UseVisualStyleBackColor = true;
			this->btn3->Click += gcnew System::EventHandler(this, &Form1::btn3_Click);
			// 
			// btn2
			// 
			this->btn2->Location = System::Drawing::Point(192, 46);
			this->btn2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn2->Name = L"btn2";
			this->btn2->Size = System::Drawing::Size(68, 30);
			this->btn2->TabIndex = 31;
			this->btn2->Text = L"2";
			this->btn2->UseVisualStyleBackColor = true;
			this->btn2->Click += gcnew System::EventHandler(this, &Form1::btn2_Click_1);
			// 
			// btn1
			// 
			this->btn1->Location = System::Drawing::Point(118, 46);
			this->btn1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn1->Name = L"btn1";
			this->btn1->Size = System::Drawing::Size(68, 30);
			this->btn1->TabIndex = 30;
			this->btn1->Text = L"1";
			this->btn1->UseVisualStyleBackColor = true;
			this->btn1->Click += gcnew System::EventHandler(this, &Form1::btn1_Click_1);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(117, 11);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(216, 26);
			this->textBox1->TabIndex = 29;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(464, 720);
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
			this->Controls->Add(this->btnC);
			this->Controls->Add(this->btnB);
			this->Controls->Add(this->btnA);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->btnCE);
			this->Controls->Add(this->btnDot);
			this->Controls->Add(this->btn0);
			this->Controls->Add(this->btn9);
			this->Controls->Add(this->btn8);
			this->Controls->Add(this->btn7);
			this->Controls->Add(this->btn6);
			this->Controls->Add(this->btn5);
			this->Controls->Add(this->btn4);
			this->Controls->Add(this->btn3);
			this->Controls->Add(this->btn2);
			this->Controls->Add(this->btn1);
			this->Controls->Add(this->textBox1);
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion




	private: System::Void btn1_Click_1(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text = textBox1->Text + "1";
	}
	private: System::Void btn2_Click_1(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text = textBox1->Text + "2";
	}
	private: System::Void btn3_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text = textBox1->Text + "3";
	}
	private: System::Void btn4_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text = textBox1->Text + "4";
	}
	private: System::Void btn5_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text = textBox1->Text + "5";
	}
	private: System::Void btn6_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text = textBox1->Text + "6";
	}
	private: System::Void btn7_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text = textBox1->Text + "7";
	}
	private: System::Void btn8_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text = textBox1->Text + "8";
	}
	private: System::Void btn9_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text = textBox1->Text + "9";
	}
	private: System::Void btn0_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text = textBox1->Text + "0";
	}
	private: System::Void btnDot_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text = textBox1->Text + ".";
	}
	private: System::Void btnCE_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text = "";
	}




	private: System::Void btnA_Click(System::Object^ sender, System::EventArgs^ e) {
		//Using the ATM object, make a state check to see where the program is at, then 
		// call the atm function that changes the appearance. This is the same for btns A B C.
		switch (GUIATM->GetState())
		{
		case 0:
			int NewCustNum;
			// This MUST work, or else user didn't enter a valid integer.
			if (System::Int32::TryParse(textBox1->Text, NewCustNum)) {
				// conversion succeeded, num now holds the parsed integer value
				GUIATM->SetCustomerNumber(NewCustNum);
				AcctNumTB->Text = textBox1->Text;

				textBox1->Text = ""; //Clear textbox
				StateTB->Text = "Pin";
				textBox2->Text = "Enter PIN and press OK";

				btnA->Text = "OK";
				btnB->Text = "";
				btnC->Text = "";

				break;
			}
			break;
		case 1:
			int NewPinNum;
			if (System::Int32::TryParse(textBox1->Text, NewPinNum)) {
				// conversion succeeded, num now holds the parsed integer value
				GUIATM->SelectCustomer(NewPinNum); //If this does not work, prog crash.
				PinNumberTB->Text = textBox1->Text;

				textBox1->Text = ""; //Clear textbox
				StateTB->Text = "Account Select";
				textBox2->Text = "Select Account";

				btnA->Text = "Checkings";
				btnB->Text = "Savings";
				btnC->Text = "Cancel";

				break;
			}
			break;
		case 2:
			//Customer selected checkings.
			GUIATM->SelectAccnt(ATM::AccountType::Checkings);
			AcctTypeTB->Text = "Checkings";

			textBox1->Text = ""; //Clear textbox
			StateTB->Text = "Transaction";
			
			//Making current balance into a string.
			textBox2->Text = "Balance = " + System::Convert::ToString(GUIATM->GetBalance()) + 
				Environment::NewLine + "Enter amount and select transaction";
			
			btnA->Text = "Withdraw";
			btnB->Text = "Deposit";
			btnC->Text = "Cancel";
			
			break;
		case 3:

			double WD_Value;
			if (System::Double::TryParse(textBox1->Text, WD_Value)) {
				
				TransTypeTB->Text = "Withdrawal";
				TransactionTB->Text = textBox1->Text;

				textBox1->Text = "";
				GUIATM->Withdraw(WD_Value);
				textBox2->Text = "Balance = " + System::Convert::ToString(GUIATM->GetBalance()) 
					+ Environment::NewLine + "Enter amount and select transaction"; "\nEnter amount and select transaction";

				//No changes to button labels

				break;
			}
			break;}
	}
	private: System::Void btnB_Click(System::Object^ sender, System::EventArgs^ e) {
		switch (GUIATM->GetState())
		{
		case 0:
			break; //Do nothing... empty button.
		case 1:
			break; //Again do nothing... empty button.
		case 2:
			//Customer selected savings.
			GUIATM->SelectAccnt(ATM::AccountType::Savings);
			AcctTypeTB->Text = "Savings";

			textBox1->Text = ""; //Clear textbox
			StateTB->Text = "Transaction";

			//Making current balance into a string.
			textBox2->Text = "Balance = " + System::Convert::ToString(GUIATM->GetBalance())
				+ Environment::NewLine + "Enter amount and select transaction"; "\nEnter amount and select transaction";;
			
			btnA->Text = "Withdraw";
			btnB->Text = "Deposit";
			btnC->Text = "Cancel";
			
			break;

		case 3:
			double D_Value;
			if (System::Double::TryParse(textBox1->Text, D_Value)) {

				TransTypeTB->Text = "Deposit";
				TransactionTB->Text = textBox1->Text;

				textBox1->Text = "";
				GUIATM->Deposit(D_Value);
				textBox2->Text = "Balance = " + System::Convert::ToString(GUIATM->GetBalance())
					+ Environment::NewLine + "Enter amount and select transaction"; "\nEnter amount and select transaction";

				//No changes to button labels.
				break;
			}
			break;
		}
	}
	private: System::Void btnC_Click(System::Object^ sender, System::EventArgs^ e) {
		switch (GUIATM->GetState())
		{
		case 0:
			GUIATM->CloseAll(); //Closes entire program.
			break;
		case 1:
			break; //Do nothing... empty button.
		case 2:
			//These are CANCEL buttons, so the ATM must go back.
			//However, because this is in Account mode, it'll reset back to start.

			//Giving start UI look with buttons and textboxes.
			GUIATM->Reset();
			textBox1->Text = "";
			textBox2->Text = "Enter customer number and press OK.";
			StateTB->Text = "Start";

			btnA->Text = "OK";
			btnB->Text = "";
			btnC->Text = "Exit";

			//Clearing all textboxes
			AcctNumTB->Text = "";
			PinNumberTB->Text = "";
			AcctTypeTB->Text = "";
			TransTypeTB->Text = "";
			TransactionTB->Text = "";

			break;
		case 3:
			GUIATM->back(); //Going back to Account state.

			textBox1->Text = "";
			textBox2->Text = "Select Account";
			StateTB->Text = "Account Select";

			AcctTypeTB->Text = "";
			TransTypeTB->Text = "";
			TransactionTB->Text = "";

			btnA->Text = "Checkings";
			btnB->Text = "Savings";
			btnC->Text = "Cancel";
			break;
		}
	}

	//Probably nothing but can't delete that or problems...
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {

	}

	};
};