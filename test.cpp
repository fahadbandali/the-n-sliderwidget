#include "test.h"


test::test(const wxString& title)
	: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(1500, 700))
{
	wxPanel* panel = new wxPanel(this);

	int practice[8] = { 500,1000,1500,2000,2049,2949,1003,3506 };
	multi(panel, 8, practice, 3600);



}

void test::multi(wxPanel* panel, int n, int* max_array_ordered, int absolute_max) {

	wxImage::AddHandler(new wxPNGHandler);
	wxBitmapButton *playbutton = new wxBitmapButton(panel, wxID_ANY, wxBitmap(wxT("newplay.png"),
		wxBITMAP_TYPE_PNG));
	wxBitmapButton *pausebutton = new wxBitmapButton(panel, wxID_ANY, wxBitmap(wxT("newpause.png"),
		wxBITMAP_TYPE_PNG));
	wxBitmapButton *forwardbutton = new wxBitmapButton(panel, wxID_ANY, wxBitmap(wxT("newforward.png"),
		wxBITMAP_TYPE_PNG));
	wxBitmapButton *rewindbutton = new wxBitmapButton(panel, wxID_ANY, wxBitmap(wxT("newrewind.png"),
		wxBITMAP_TYPE_PNG));

	wxBoxSizer *mainSizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer *mediaSizer = new wxBoxSizer(wxVERTICAL);

	for (int i = 0; i < n; i++) {
		customwidgetslider *slider = new customwidgetslider(panel, max_array_ordered[i], max_array_ordered[i], absolute_max);
		sliders.push_back(slider);

		wxBoxSizer *fullsizer = new wxBoxSizer(wxHORIZONTAL);
		fullsizer->Add(slider, 1, wxEXPAND | wxALL, 8);

		mediaSizer->Add(fullsizer, 1, wxEXPAND);
	}

	wxBoxSizer *controlsSizer = new wxBoxSizer(wxHORIZONTAL);
	controlsSizer->Add(rewindbutton, 1, wxRIGHT, 40);
	controlsSizer->Add(pausebutton, 1, wxRIGHT | wxLEFT, 10);
	controlsSizer->Add(playbutton, 1, wxRIGHT | wxLEFT, 10);
	controlsSizer->Add(forwardbutton, 1, wxLEFT, 40);
	mediaSizer->Add(controlsSizer, 0, wxTOP | wxALIGN_TOP | wxALIGN_CENTER_HORIZONTAL, 20);

	mainSizer->Add(mediaSizer, 1, wxALIGN_CENTER_VERTICAL | wxALIGN_CENTER_HORIZONTAL);

	wxBoxSizer *stepSizer = new wxBoxSizer(wxVERTICAL);
	Spin = new wxSpinCtrl(panel, wxID_ANY, _("1"));
	stepSizer->Add(Spin, 1, wxLEFT, 20);
	mainSizer->Add(stepSizer, 0, wxALIGN_CENTER_VERTICAL);

	panel->SetSizer(mainSizer);

	Bind(wxEVT_COMMAND_SPINCTRL_UPDATED, &test::GetTestStepValue, this);
	Bind(wxEVT_IDLE, &test::onIdle, this);

}

void test::GetTestStepValue(wxSpinEvent& event)
{
	int daddyspinctrlval = Spin->GetValue();
	for (int r = 0; r < sliders.size(); r++) {
		sliders.at(r)->SetcustomStepValue(daddyspinctrlval);
	}

}


void test::onIdle(wxIdleEvent& evt)
{
	if (render) {
		int our_value;
		//int our_value = sliders[0]->GetcustomMainValue();
		for (int p = 0; p < sliders.size(); p++) {
			if (sliders[p]->GetCheck()) {
				checked_sliders.push_back(sliders.at(p));
				our_value = checked_sliders[0]->GetcustomMainValue();
			}
		}

		//match
		if (checked_sliders.size() > 1) {
			for (int c = 0; c < checked_sliders.size(); c++) {
				checked_sliders.at(c)->SetcustomMainValue(our_value);
			}
		}

		//if (our_value > 0) {
		//	for (int r = 0; r < sliders.size(); r++) {
		//		sliders.at(r)->SetcustomMainValue(our_value);
		//	}
		//}

		//for the case that it as been clicked but now there are none
		Refresh();
		Update();
		
	
	}
}



//then add sync, adding the grey scale thing