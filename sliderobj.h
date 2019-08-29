#ifndef SLIDEROBJ
#define SLIDEROBJ

#include<wx/wx.h>
#include <wx/checkbox.h>
#include <wx/dcbuffer.h>

class singlesliderobj : public wxPanel
{
public:
	singlesliderobj(wxPanel* parent,
		int id,
		int mainValue, int minValue, int maxValue, int absoluteMax,
		const wxPoint&pos = wxDefaultPosition,
		const wxSize& size = wxSize(-1, 85),
		long style = wxSL_HORIZONTAL | wxSL_SELRANGE);

	void SetMainValue(int mainval);
	int GetMainValue();
	void SetMinValue(int minval);
	int GetMinValue();
	void SetMaxValue(int maxval);
	int GetMaxValue();
	int GetSliderID();


	void OnPaint(wxPaintEvent &);
	void paintNow();
	void OnRepaint(wxEraseEvent& event);

	void SetStepVal(int stepvalue);
	int GetStepVal();

	void OnSize(wxSizeEvent & event);
	void OnLeftDown(wxMouseEvent & event);
	void OnMotion(wxMouseEvent & event);
	void OnLeftUp(wxMouseEvent & event);
	void OnWheel(wxMouseEvent & event);
	int mainValue;

protected:
	void DrawThumb(wxDC& dc, wxCoord x, wxCoord y);
	void render(wxDC & dc);


private:
	int minValue, maxValue;
	int selectedslider, prevx, prevy;
	int ID_new;
	int step = 100;
	DECLARE_EVENT_TABLE()
};



#endif