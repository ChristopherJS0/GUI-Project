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
	/// Summary for Form2
	/// </summary>
	public ref class Form2 : public System::Windows::Forms::Form
	{
		//Will use this for buttons.
	private: int FormState;
		   Client^ FormClient;
	public:
		Form2(void)
		{
			InitializeComponent();
			FormClient = gcnew Client();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form2()
		{
			if (components)
			{
				delete components;
			}
		}
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
	private: System::Windows::Forms::Button^ btnC;
	private: System::Windows::Forms::Button^ btnB;
	private: System::Windows::Forms::Button^ btnA;
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
			this->btnC = (gcnew System::Windows::Forms::Button());
			this->btnB = (gcnew System::Windows::Forms::Button());
			this->btnA = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// btnCE
			// 
			this->btnCE->Location = System::Drawing::Point(215, 159);
			this->btnCE->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnCE->Name = L"btnCE";
			this->btnCE->Size = System::Drawing::Size(60, 24);
			this->btnCE->TabIndex = 53;
			this->btnCE->Text = L"CE";
			this->btnCE->UseVisualStyleBackColor = true;
			this->btnCE->Click += gcnew System::EventHandler(this, &Form2::btnCE_Click);
			// 
			// btnDot
			// 
			this->btnDot->Location = System::Drawing::Point(150, 159);
			this->btnDot->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnDot->Name = L"btnDot";
			this->btnDot->Size = System::Drawing::Size(60, 24);
			this->btnDot->TabIndex = 52;
			this->btnDot->Text = L".";
			this->btnDot->UseVisualStyleBackColor = true;
			this->btnDot->Click += gcnew System::EventHandler(this, &Form2::btnDot_Click);
			// 
			// btn0
			// 
			this->btn0->Location = System::Drawing::Point(84, 159);
			this->btn0->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn0->Name = L"btn0";
			this->btn0->Size = System::Drawing::Size(60, 24);
			this->btn0->TabIndex = 51;
			this->btn0->Text = L"0";
			this->btn0->UseVisualStyleBackColor = true;
			this->btn0->Click += gcnew System::EventHandler(this, &Form2::btn0_Click);
			// 
			// btn9
			// 
			this->btn9->Location = System::Drawing::Point(215, 130);
			this->btn9->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn9->Name = L"btn9";
			this->btn9->Size = System::Drawing::Size(60, 24);
			this->btn9->TabIndex = 50;
			this->btn9->Text = L"9";
			this->btn9->UseVisualStyleBackColor = true;
			this->btn9->Click += gcnew System::EventHandler(this, &Form2::btn9_Click);
			// 
			// btn8
			// 
			this->btn8->Location = System::Drawing::Point(150, 130);
			this->btn8->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn8->Name = L"btn8";
			this->btn8->Size = System::Drawing::Size(60, 24);
			this->btn8->TabIndex = 49;
			this->btn8->Text = L"8";
			this->btn8->UseVisualStyleBackColor = true;
			this->btn8->Click += gcnew System::EventHandler(this, &Form2::btn8_Click);
			// 
			// btn7
			// 
			this->btn7->Location = System::Drawing::Point(84, 130);
			this->btn7->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn7->Name = L"btn7";
			this->btn7->Size = System::Drawing::Size(60, 24);
			this->btn7->TabIndex = 48;
			this->btn7->Text = L"7";
			this->btn7->UseVisualStyleBackColor = true;
			this->btn7->Click += gcnew System::EventHandler(this, &Form2::btn7_Click);
			// 
			// btn6
			// 
			this->btn6->Location = System::Drawing::Point(215, 102);
			this->btn6->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn6->Name = L"btn6";
			this->btn6->Size = System::Drawing::Size(60, 24);
			this->btn6->TabIndex = 47;
			this->btn6->Text = L"6";
			this->btn6->UseVisualStyleBackColor = true;
			this->btn6->Click += gcnew System::EventHandler(this, &Form2::btn6_Click);
			// 
			// btn5
			// 
			this->btn5->Location = System::Drawing::Point(150, 102);
			this->btn5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn5->Name = L"btn5";
			this->btn5->Size = System::Drawing::Size(60, 24);
			this->btn5->TabIndex = 46;
			this->btn5->Text = L"5";
			this->btn5->UseVisualStyleBackColor = true;
			this->btn5->Click += gcnew System::EventHandler(this, &Form2::btn5_Click);
			// 
			// btn4
			// 
			this->btn4->Location = System::Drawing::Point(84, 102);
			this->btn4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn4->Name = L"btn4";
			this->btn4->Size = System::Drawing::Size(60, 24);
			this->btn4->TabIndex = 45;
			this->btn4->Text = L"4";
			this->btn4->UseVisualStyleBackColor = true;
			this->btn4->Click += gcnew System::EventHandler(this, &Form2::btn4_Click);
			// 
			// btn3
			// 
			this->btn3->Location = System::Drawing::Point(215, 73);
			this->btn3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn3->Name = L"btn3";
			this->btn3->Size = System::Drawing::Size(60, 24);
			this->btn3->TabIndex = 44;
			this->btn3->Text = L"3";
			this->btn3->UseVisualStyleBackColor = true;
			this->btn3->Click += gcnew System::EventHandler(this, &Form2::btn3_Click);
			// 
			// btn2
			// 
			this->btn2->Location = System::Drawing::Point(150, 73);
			this->btn2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn2->Name = L"btn2";
			this->btn2->Size = System::Drawing::Size(60, 24);
			this->btn2->TabIndex = 43;
			this->btn2->Text = L"2";
			this->btn2->UseVisualStyleBackColor = true;
			this->btn2->Click += gcnew System::EventHandler(this, &Form2::btn2_Click);
			// 
			// btn1
			// 
			this->btn1->Location = System::Drawing::Point(84, 73);
			this->btn1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn1->Name = L"btn1";
			this->btn1->Size = System::Drawing::Size(60, 24);
			this->btn1->TabIndex = 42;
			this->btn1->Text = L"1";
			this->btn1->UseVisualStyleBackColor = true;
			this->btn1->Click += gcnew System::EventHandler(this, &Form2::btn1_Click);
			// 
			// btnC
			// 
			this->btnC->Location = System::Drawing::Point(124, 253);
			this->btnC->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnC->Name = L"btnC";
			this->btnC->Size = System::Drawing::Size(109, 29);
			this->btnC->TabIndex = 56;
			this->btnC->Text = L"Exit";
			this->btnC->UseVisualStyleBackColor = true;
			this->btnC->Click += gcnew System::EventHandler(this, &Form2::btnC_Click);
			// 
			// btnB
			// 
			this->btnB->Location = System::Drawing::Point(124, 220);
			this->btnB->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnB->Name = L"btnB";
			this->btnB->Size = System::Drawing::Size(109, 29);
			this->btnB->TabIndex = 55;
			this->btnB->UseVisualStyleBackColor = true;
			this->btnB->Click += gcnew System::EventHandler(this, &Form2::btnB_Click);
			// 
			// btnA
			// 
			this->btnA->Location = System::Drawing::Point(124, 187);
			this->btnA->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnA->Name = L"btnA";
			this->btnA->Size = System::Drawing::Size(109, 29);
			this->btnA->TabIndex = 54;
			this->btnA->Text = L"OK";
			this->btnA->UseVisualStyleBackColor = true;
			this->btnA->Click += gcnew System::EventHandler(this, &Form2::btnA_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(83, 25);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(192, 22);
			this->textBox1->TabIndex = 57;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form2::textBox1_TextChanged);
			// 
			// Form2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(360, 309);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->btnC);
			this->Controls->Add(this->btnB);
			this->Controls->Add(this->btnA);
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
			this->Name = L"Form2";
			this->Text = L"Form2";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btn1_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text += "1";
	}
	private: System::Void btn2_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text += "2";
	}
	private: System::Void btn3_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text += "3";
	}
	private: System::Void btn4_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text += "4";
	}
	private: System::Void btn5_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text += "5";
	}
	private: System::Void btn6_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text += "6";
	}
	private: System::Void btn7_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text += "7";
	}
	private: System::Void btn8_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text += "8";
	}
	private: System::Void btn9_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text += "9";
	}
	private: System::Void btn0_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text += "0";
	}
	private: System::Void btnDot_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text += ".";
	}
	private: System::Void btnCE_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text = "";
	}


	private: System::Void btnA_Click(System::Object^ sender, System::EventArgs^ e) {
		switch (FormState) {
		case 0:
			if (textBox1->Text != "")
			{
				try
				{
					int AcctNum = Int32::Parse(textBox1->Text);
					FormClient->SendAcctNum(AcctNum);
					textBox1->Text = "";
				}
				catch (FormatException^)
				{
					textBox1->Text = "";
					break;
				}
			}

			btnA->Text = "OK";
			btnB->Text = "";
			btnC->Text = "";
			FormState = 1;
			break;
		case 1:
			if (textBox1->Text != "")
			{
				try
				{
					int PinNum = Int32::Parse(textBox1->Text);
					FormClient->SendPinNum(PinNum);
					textBox1->Text = "";
				}
				catch (FormatException^)
				{
					textBox1->Text = "";
					break;
				}
			}
			FormState = 2;

			btnA->Text = "Checkings";
			btnB->Text = "Savings";
			btnC->Text = "Cancel";

			break;
		case 2:
			textBox1->Text = "";
			FormClient->GoToCheckings();

			//Make changes to UI: Button changes
			btnA->Text = "Withdraw";
			btnB->Text = "Deposit";
			btnC->Text = "Cancel";

			FormState = 3;
			break;

		case 3:
			try
			{
				double myDouble = System::Double::Parse(textBox1->Text);
				FormClient->WithdrawThis(myDouble);
				textBox1->Text = "";
			}
			catch (FormatException^)
			{
				textBox1->Text = "";
				break;
			}

			//No changes to UI.
			break;
		}
	}
private: System::Void btnB_Click(System::Object^ sender, System::EventArgs^ e) {
	switch (FormState) {
	case 0: //Do Nothing
		break;
	case 1: //Do Nothing
		break;
	case 2:
		textBox1->Text = "";
		FormClient->GoToSavings();

		btnA->Text = "Withdraw";
		btnB->Text = "Deposit";
		btnC->Text = "Cancel";

		FormState = 3;
		break;
	case 3:
		try
		{
			double myDouble = System::Double::Parse(textBox1->Text);
			FormClient->DepositThis(myDouble);
		}
		catch (FormatException^)
		{
			textBox1->Text = "";
			break;
		}

		//No Changes to UI.
		textBox1->Text = "";
		break;
	}
}
private: System::Void btnC_Click(System::Object^ sender, System::EventArgs^ e) {
	switch (FormState) {
	case 0:
		FormClient->CloseCliAndSer();
		Close();
		break;
	case 1: //Do nothing
		break;
	case 2:
		
		//1 Because it prompts server to go back to Accnt State.
		FormClient->GoBackReq(1); 
		
		//UI Changes to FormState AccountNum
		btnA->Text = "OK";
		btnB->Text = "";
		btnC->Text = "Exit";

		FormState = 0;
		break;

	case 3:
		FormState = 2; //Going back to Checkings/Savings
		FormClient->GoBackReq(2);

		btnA->Text = "Checkings";
		btnB->Text = "Savings";
		btnC->Text = "Cancel";

		break;
	}
	}
	};
}
