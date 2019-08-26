#include "customwidgetslider.h"

customwidgetslider::customwidgetslider(wxPanel *parent, int currentvalue, int maxVal)
	: wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(1000,1000))
{
	Oninit(parent, currentvalue, maxVal);

	
}

void customwidgetslider::Oninit(wxPanel* panel, int currentvalue, int maxVal)
{
	id = rand();
	
	playerSizer = new wxBoxSizer(wxHORIZONTAL);
	slider = new singlesliderobj(panel, id, currentvalue, 0, maxVal, wxDefaultPosition, wxSize(-1, 85), wxSL_HORIZONTAL | wxSL_SELRANGE);
	//wxBoxSizer *slidersizer = new wxBoxSizer(wxHORIZONTAL);
	//slidercheck = new wxCheckBox(panel, wxID_ANY, "sync");
	//TimeText = new wxTextCtrl(panel, wxID_ANY, _("Time"));
	//FrameText = new wxTextCtrl(panel, wxID_ANY, _("Frame"));

	//slidersizer->Add(slidercheck, 1, wxLEFT);
	//slidersizer->Add(TimeText, 1, wxRIGHT);
	//slidersizer->Add(FrameText, 1, wxRIGHT);

	//playerSizer->Add(slidersizer, 0, wxALIGN_CENTER_VERTICAL);
	playerSizer->Add(slider, maxVal, wxEXPAND);

	//Bind(wxEVT_CHECKBOX, &customwidgetslider::SetCheck,this);

}

wxBoxSizer* customwidgetslider::GetPlayerSizer()
{
	return playerSizer;
}

void customwidgetslider::SetCheck(wxCommandEvent& event)
{
	 check = slidercheck->GetValue();
	 Refresh();
	 Update();
	 
}

bool customwidgetslider::GetCheck()
{
	return check;
	
}

void customwidgetslider::SetcustomMainValue(int mainval)
{
	slider->SetMainValue(mainval);
	
}

int customwidgetslider::GetcustomMainValue()
{
	return slider->GetMainValue();
}

void customwidgetslider::SetcustomMinValue(int minval)
{
	slider->SetMinValue(minval);
}

int customwidgetslider::GetcustomMinValue()
{
	return slider->GetMinValue();
}

void customwidgetslider::SetcustomMaxValue(int maxval)
{
	slider->SetMaxValue(maxval);
}

int customwidgetslider::GetcustomMaxValue()
{
	return slider->GetMaxValue();
}

void customwidgetslider::SetcustomStepValue(int stepval)
{
	slider->SetStepVal(stepval);
}

int customwidgetslider::GetcustomStepValue()
{
	return slider->GetStepVal();
}

int customwidgetslider::GetcustomSliderID()
{
	return 0;
}

//void customwidgetslider::OnLeftDown(wxMouseEvent& event)
//{
//	int w, h;
//	wxClientDC dc(this);
//	dc.GetSize(&w, &h);
//	double mainslidervalue = ((double)slider->GetMainValue() / (double)slider->GetMaxValue()) * (double)w / 1.3;
//	wxPoint pos = event.GetLogicalPosition(dc);
//	pos.x = pos.x;
//	pos.y = h - pos.y;
//	
//	if (abs(mainslidervalue - pos.x) < 25) {
//		selectedslider = 1;
//
//	}
//
//	prevx = pos.x;
//	prevy = pos.y;
//	event.Skip();
//
//}

