#include "Classes.h"
#include "Form1.h"
//Christopher Salinas-Sanchez
//Due March 21

using namespace System;
using namespace System::Windows::Forms;
using namespace CppGUIProject2;
[STAThread]

int main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Form1());

	//IMPORTANT: The acct numbers needed to run the program will be in the Form1.h file at the top!

	return 0;
}