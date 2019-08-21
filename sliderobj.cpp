//this is the slider object class
//in this class a static version of the slider is built 
//only get and set values for the slider tab will be found here

#include "sliderobj.h"

BEGIN_EVENT_TABLE(singlesliderobj, wxPanel)
	EVT_ERASE_BACKGROUND(singlesliderobj::OnRepaint)
END_EVENT_TABLE()

static const wxCoord SLIDER_MARGIN = 1;

singlesliderobj::singlesliderobj(wxPanel *parent,
	int id,
	int mainValue, int minValue, int maxValue,
	const wxPoint& pos,
	const wxSize& size,
	long style)
	: wxPanel(parent,id, pos,size, wxBORDER_NONE)

{
	this->mainValue = mainValue;
	this->minValue = minValue;
	this->maxValue = maxValue;
	this->ID_new = id;
	SetDoubleBuffered(true);

	Bind(wxEVT_LEFT_DOWN, &singlesliderobj::OnLeftDown, this);
	Bind(wxEVT_MOTION, &singlesliderobj::OnMotion, this);
	Bind(wxEVT_LEFT_UP, &singlesliderobj::OnLeftUp, this);

	Connect(wxEVT_PAINT, wxPaintEventHandler(singlesliderobj::OnPaint));
	Connect(wxEVT_SIZE, wxSizeEventHandler(singlesliderobj::OnSize));
}

void singlesliderobj::SetMainValue(int mval) {

	mainValue = mval;
	Refresh();
	Update();
}

int singlesliderobj::GetMainValue() {

	return mainValue;
}

void singlesliderobj::SetMinValue(int minval) {

	minValue = minval;
}

int singlesliderobj::GetMinValue() {

	return minValue;
}

void singlesliderobj::SetMaxValue(int maxval) {

	maxValue = maxval;
}

int singlesliderobj::GetMaxValue() {

	return maxValue;
}

int singlesliderobj::GetSliderID() {
	
	return ID_new;

}


void singlesliderobj::OnPaint(wxPaintEvent&) {
	
	wxPaintDC dc(this);
	render(dc);
}

void singlesliderobj::paintNow()
{
	wxClientDC dc(this);
	render(dc);
}

void singlesliderobj::OnRepaint(wxEraseEvent & event)
{
	event.Skip();
}

void singlesliderobj::DrawThumb(wxDC& dc, wxCoord x, wxCoord y) {
	
	dc.SetPen(wxColour("#447aee")); //for right pointer tip
	dc.DrawLine(x + 10, y + 16, x + 4, y + 22);
	dc.DrawLine(x + 10, y + 0, x + 10, y + 17);
	dc.DrawLine(x + 3, y + 17, x + 8, y + 17);

	dc.SetPen(wxColour("#447aee")); //for right pointer tip
	dc.DrawLine(x + 5, y + 20, x + 10, y + 15);
	dc.DrawLine(x + 9, y + 1, x + 9, y + 17);

	dc.SetPen(wxColour("#447aee")); //red right slider
	dc.DrawLine(x + 4, y + 21, x + 0, y + 17);
	dc.DrawLine(x + 5, y + 20, x + 0, y + 15);
	dc.DrawLine(x + 5, y + 19, x + 3, y + 17);
	dc.DrawLine(x + 5, y + 18, x + 7, y + 18);
	for (int i = 1; i <= 8; i++) dc.DrawLine(x + i - 5, y + 15, x + i - 5, y - 30);
	for (int i = 1; i <= 8; i++) dc.DrawLine(x + i + 3, y + 15, x + i + 3, y - 30);

}

void singlesliderobj::render(wxDC& dc) {
	
	int w, h;
	GetSize(&w, &h);
	wxCoord tw, th;

	//media bar
	dc.SetPen(wxPen(wxColor(0, 0, 0), 7));
	dc.DrawLine(SLIDER_MARGIN, h / 2 - 1, w / 1.3 + 15, h / 2 - 1);
	dc.SetPen(wxPen(wxColor(0, 0, 0), 7));
	dc.DrawLine(SLIDER_MARGIN, h / 2, w / 1.3 + 15, h / 2);
	dc.SetPen(wxPen(wxColor(0, 0, 0), 7));
	dc.DrawLine(SLIDER_MARGIN, h / 2 + 1, w / 1.3 + 15, h / 2 + 1);
	dc.SetPen(wxPen(wxColor(0, 0, 0), 10));
	dc.DrawLine(SLIDER_MARGIN, h / 2 + 1, w / 1.3 + 15, h / 2 + 1);


	//main slider:
	double mainslidervalue = ((double)mainValue / (double)maxValue) * (double)w / 1.3;
	dc.GetTextExtent(wxString::Format("%d", mainValue), &tw, &th);
	DrawThumb(dc, SLIDER_MARGIN + mainslidervalue + 2, h*0.5 - th + 10);
	if (mainValue < maxValue / 2)
		dc.DrawText(wxString::Format("%d", mainValue), SLIDER_MARGIN + mainslidervalue + 20, h*0.5 + 5);
	else
		dc.DrawText(wxString::Format("%d", mainValue), SLIDER_MARGIN + mainslidervalue - tw - 12, h*0.5 + 5);

}

void singlesliderobj::OnSize(wxSizeEvent& event) {
	Refresh();
	Update();
}

void singlesliderobj::OnLeftDown(wxMouseEvent& event)
{
	int w, h;
	wxClientDC dc(this);
	dc.GetSize(&w, &h);
	double mainslidervalue = ((double)this->GetMainValue() / (double)this->GetMaxValue()) * (double)w / 1.3;
	wxPoint pos = event.GetLogicalPosition(dc);
	pos.x = pos.x;
	pos.y = h - pos.y;
	
	if (abs(mainslidervalue - pos.x) < 25) {
		selectedslider = 1;

	}

	prevx = pos.x;
	prevy = pos.y;
	event.Skip();

}

void singlesliderobj::OnMotion(wxMouseEvent& event)
{
	int w, h;
	int m = 100;
	//int m = step;
	if (selectedslider != 0) {
		wxClientDC dc(this);
		dc.GetSize(&w, &h);
		wxPoint pos = event.GetLogicalPosition(dc);
		pos.x = pos.x - SLIDER_MARGIN;
		pos.y = h - SLIDER_MARGIN - pos.y;

		if (prevx - pos.x > 0)
			m = -m; //THESE CHANGE THE STEP SIZE
		/*if (test == 1) m = pos.x - prevx;*/

		if (selectedslider == 1) {
			mainValue += m;
			if (mainValue < minValue)  mainValue = minValue;
			if (mainValue >= maxValue) mainValue = maxValue;
		}
		prevx = pos.x;
		prevy = pos.y;
		Refresh();
		//Update();
	}
	event.Skip();
}

void singlesliderobj::OnLeftUp(wxMouseEvent& event)
{
	/*event.Skip();*/
	if (selectedslider != 0) {
		selectedslider = 0;
		wxCommandEvent e(wxEVT_SCROLL_CHANGED);
		e.SetEventObject(this);
		e.SetString("update");
		ProcessWindowEvent(e);
	}
}