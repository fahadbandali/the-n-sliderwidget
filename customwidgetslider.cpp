#include "customwidgetslider.h"

customwidgetslider::customwidgetslider(wxPanel *parent, int currentvalue, int maxVal, int absoluteMax)
	: wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(1000, 85))
{
	Oninit(this, currentvalue, maxVal, absoluteMax);
}

void customwidgetslider::Oninit(wxPanel* panel, int currentvalue, int maxVal, int absoluteMax)
{
	id = rand();

	playerSizer = new wxBoxSizer(wxHORIZONTAL);
	slider = new singlesliderobj(panel, id, currentvalue, 0, maxVal, absoluteMax, wxDefaultPosition, wxSize(-1, 85), wxSL_HORIZONTAL | wxSL_SELRANGE);
	wxBoxSizer *slidersizer = new wxBoxSizer(wxHORIZONTAL);
	slidercheck = new wxCheckBox(panel, wxID_ANY, "sync");
	TimeText = new wxTextCtrl(panel, wxID_ANY, _("Time"));
	FrameText = new wxTextCtrl(panel, wxID_ANY, _("Frame"));

	slidersizer->Add(slidercheck, 1, wxLEFT);
	slidersizer->Add(TimeText, 1, wxRIGHT);
	slidersizer->Add(FrameText, 1, wxRIGHT);

	playerSizer->Add(slidersizer, 0, wxALIGN_CENTER_VERTICAL);
	playerSizer->Add(slider, maxVal, wxEXPAND);
	playerSizer->AddStretchSpacer(absoluteMax - maxVal);
	SetSizer(playerSizer);

	Bind(wxEVT_CHECKBOX, &customwidgetslider::SetCheck,this);
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
	return id;
}

