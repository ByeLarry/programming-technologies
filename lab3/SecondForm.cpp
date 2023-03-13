#include "SecondForm.h"

using namespace System;
using namespace System::Windows::Forms;


int mainsecond(array <String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	String^ path;
	lab3::SecondForm form(path);
	Application::Run(% form);
	return 0;
}