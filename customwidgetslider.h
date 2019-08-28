#ifndef CUSTOMOBJ
#define CUSTOMOBJ

#include <wx/wx.h>
#include <wx/checkbox.h>
#include "sliderobj.h"
#include "stdlib.h"


class customwidgetslider : public wxPanel
{
public:
	customwidgetslider(wxPanel* parent, int currentvalue, int maxVal, int absoluteMax);

	void Oninit(wxPanel * panel, int currentvalue, int maxVal, int absoluteMax);
	// wxBoxSizer* GetPlayerSizer();
	void SetCheck(wxCommandEvent& event);
	bool GetCheck();
	void SetcustomMainValue(int mainval);
	int GetcustomMainValue();
	void SetcustomMinValue(int minval);
	int GetcustomMinValue();
	void SetcustomMaxValue(int maxval);
	int GetcustomMaxValue();
	void SetcustomStepValue(int stepval);
	int GetcustomStepValue();
	int GetcustomSliderID();

	singlesliderobj* slider;
	wxCheckBox* slidercheck;
	wxTextCtrl *TimeText;
	wxTextCtrl *FrameText;
	wxBoxSizer* playerSizer;

private:
	int prevx, prevy;
	int selectedslider;
	int id;
	bool check;

};
#endif