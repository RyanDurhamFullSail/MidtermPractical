#pragma once
#include "wx/wx.h"

class QuestionFactory;

class Window : public wxFrame
{
public:
	Window();
	~Window();

public:
	//Correct Answer
	wxString correct;

	//Buttons
	wxButton **buttons;


	//Static Texts
	wxStaticText* question;
	wxStaticText** answers;


	//Panel
	wxPanel* panel;

	QuestionFactory* questionFactory = nullptr;

	void OnButtonClicked(wxCommandEvent& evt);
};

