#include "Window.h"
#include "QuestionFactory.h"

Window::Window() : wxFrame(nullptr, -1, "Quiz Master", wxPoint(500,500), wxSize(350,300))
{
	panel = new wxPanel(this, -1);

	buttons = new wxButton * [4];
	answers = new wxStaticText * [4];

	char temp = 'A';

	wxFont font(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);

	QuestionFactory::GenerateQA(panel, question, answers, correct, font);

	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
	wxGridSizer* answerUI = new wxGridSizer(4, 2, 0, 0);

	for(int i = 0; i < 4; i++)
	{
		buttons[i] = QuestionFactory::CreateButton(panel, (wxString)temp, font);
		buttons[i]->Bind(wxEVT_BUTTON, &Window::OnButtonClicked, this);

		temp++;		

		answerUI->Add(answers[i], 1, wxEXPAND);
		answerUI->Add(buttons[i], 1, wxEXPAND);
	}

	sizer->AddSpacer(50);
	sizer->Add(question, 1, wxCENTER | wxBOTTOM);
	sizer->Add(answerUI, 1, wxEXPAND | wxCENTER);
	panel->SetSizer(sizer);

	Centre();
}

Window::~Window()
{
	delete[] answers;
	delete[] buttons;
}

void Window::OnButtonClicked(wxCommandEvent& evt)
{
	wxButton* temp = dynamic_cast<wxButton*>(evt.GetEventObject());

	// Check if user answers correctly and display message
	if(temp->GetLabel() == correct)
	{
		wxMessageBox("You Answered Correctly! - :)");
	}
	else
	{
		wxMessageBox("That is incorrect - :(");
	}

	//Reset the game
	QuestionFactory::Reset(panel, question, answers, correct);

}