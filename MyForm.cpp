#include "MyForm.h"
using namespace Window;

int main()
{
    Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);

	return 0;
}