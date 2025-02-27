//Christopher Salinas
#include "Form1.h"
#include "Form2.h"
#using <system.dll>
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Threading;
using namespace CppGUIProject2;

void RunForm1()
{
	Application::Run(gcnew Form1);
}
void RunForm2()
{
	Application::Run(gcnew Form2);
}

int main(array<String^>^ args)
{
	// Form 1: Visual representation only.
	// Form 2: Input needed in this window only.
	// Account information to use:
		// Account 1: 101 AND 101
		// Account 2: 102 AND 201
		// Account 3: 103 AND 301
		// Account 4: 104 AND 401
		// Account 5: 105 AND 501

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Thread^ Form1 = gcnew Thread(gcnew ThreadStart(RunForm1));
	Thread^ Form2 = gcnew Thread(gcnew ThreadStart(RunForm2));
	
	// Had to use threads for these forms so that they could both open at the same time!
	Form1->Start();
	Form2->Start();

	Form1->Join();
	Form2->Join();


	return 0;
}