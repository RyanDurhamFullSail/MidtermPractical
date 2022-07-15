#pragma once
#include "wx/wx.h"


class QuestionFactory
{
private:
	static wxString currentQuestion;
	static wxString currentAnswers[4];
	static wxString currentCorrect;
	static void SelectQuestionSet();
	static void SetCorrectAnswer(int correct);

public:
	static void GenerateQA(wxPanel* panel, wxStaticText*& question, wxStaticText**& answers, wxString& correct, wxFont font);
	static void Reset(wxPanel* panel, wxStaticText*& question, wxStaticText**& answers, wxString& correct);
	static wxButton* CreateButton(wxPanel* panel, const char* label, wxFont font);	

};

