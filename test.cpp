#include "test.h"


test::test(const wxString& title)
	: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(1500, 700))
{
	wxPanel* panel = new wxPanel(this);

	int practice[8] = { 500,1000,1500,2000,2049,2949,1003,3506};
	multi(panel, 1,practice);
	//wxCheckBox* testingcheck = new wxCheckBox(panel, wxID_ANY, "testingcheck");



}

void test::multi(wxPanel* panel ,int n, int* max_array_ordered) {

	wxBoxSizer *mainSizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer *mediaSizer = new wxBoxSizer(wxVERTICAL);

	for (int i = 0; i < n; i++) {
		
		sliders.push_back(new customwidgetslider(panel, max_array_ordered[i], max_array_ordered[i]));
		//wxCheckBox* testingcheck = new wxCheckBox(mainpanel, wxID_ANY, "testingcheck");
		//mediaSizer->Add(testingcheck, 1, wxLEFT);
		//wxBoxSizer *slidersizer = new wxBoxSizer(wxHORIZONTAL);
		//wxCheckBox* slidercheck = new wxCheckBox(mainpanel, wxID_ANY, "sync");
		//wxTextCtrl* TimeText = new wxTextCtrl(mainpanel, wxID_ANY, _("Time"));
		//wxTextCtrl* FrameText = new wxTextCtrl(mainpanel, wxID_ANY, _("Frame"));

		//sliders.at(i)->playerSizer->Add(slidercheck, 0, wxLEFT);
		//sliders.at(i)->playerSizer->Add(TimeText, 0, wxRIGHT);
		//sliders.at(i)->playerSizer->Add(FrameText, 0, wxRIGHT);
		//sliders.at(i)->playerSizer->Add(slidersizer, 0, wxALIGN_CENTER_VERTICAL);
		//mediaSizer->Add(sliders.at(i)->GetPlayerSizer(), 1, wxEXPAND);
		
		wxBoxSizer *fullsizer = new wxBoxSizer(wxHORIZONTAL);

		wxBoxSizer *slidersizer = new wxBoxSizer(wxHORIZONTAL);
		wxCheckBox* slidercheck = new wxCheckBox(panel, wxID_ANY, "sync");
		wxTextCtrl* TimeText = new wxTextCtrl(panel, wxID_ANY, _("Time"));
		wxTextCtrl* FrameText = new wxTextCtrl(panel, wxID_ANY, _("Frame"));

		slidersizer->Add(slidercheck, 1, wxLEFT);
		slidersizer->Add(TimeText, 1, wxRIGHT);
		slidersizer->Add(FrameText, 1, wxRIGHT);

		fullsizer->Add(slidersizer, 0, wxALIGN_CENTER_VERTICAL);
		fullsizer->Add(sliders.at(i)->GetPlayerSizer(), 1, wxEXPAND);

		mediaSizer->Add(fullsizer, 1, wxEXPAND);
	}
	
	mainSizer->Add(mediaSizer, 1, wxALIGN_CENTER_VERTICAL | wxALIGN_CENTER_HORIZONTAL);
	panel->SetSizer(mainSizer);


	//Bind(wxEVT_IDLE, &test::onIdle, this);

}

//void test::onIdle(wxIdleEvent& evt)
//{
//	if (render) {
//		
//		for (int p = 0; p < sliders.size(); p++) {
//			if (sliders[p]->GetCheck()) {
//				checked_sliders.push_back(sliders.at(p));
//			}
//		}
//
//		//match all of them
//
//		//int our_value = checked_sliders[0]->GetcustomMainValue();
//		//if (our_value > 0) {
//		//	for (int r = 0; r < sliders.size(); r++) {
//		//		sliders.at(r)->SetcustomMainValue(our_value);
//		//	}
//		//}
//		Update();
//		
//	
//	}
//}



//then add sync, adding the grey scale thing