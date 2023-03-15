#include "MainForm.h"
#include "SecondForm.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]

int main() {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	lab3::MainForm form;
	Application::Run(% form);
}