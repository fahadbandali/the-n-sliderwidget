#include "main.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit() {
	
	test* testing = new test(wxT("testing"));

	testing->Show(true);
	testing->render = 1;
	return true;
}