#ifndef TESTINGCLASS
#define TESTINGCLASS

#include <wx/wx.h>
#include "customwidgetslider.h"
#include "sliderobj.h"
#include "wx/checkbox.h"
#include <stdlib.h>
#include <vector> 
#include <iostream>
#include <thread>

#include <chrono>

class test : public wxFrame
{
public:
	test(const wxString& title);

	void multi(wxPanel* panel, int n, int* max_arrary_ordered);
	/*void onIdle(wxIdleEvent & evt);*/
	int render = 0;

private:
	std::vector<customwidgetslider*> sliders;
	std::vector<customwidgetslider*> checked_sliders;
};

#endif