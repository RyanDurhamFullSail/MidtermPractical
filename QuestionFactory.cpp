#include "QuestionFactory.h"


	wxString QuestionFactory::currentQuestion;
	wxString QuestionFactory::currentAnswers[4];
	wxString QuestionFactory::currentCorrect;


	void QuestionFactory::GenerateQA(wxPanel* panel, wxStaticText*& question, wxStaticText**& answers, wxString& correct, wxFont font)
	{
		SelectQuestionSet();
		question = new wxStaticText(panel, -1, currentQuestion);
		answers[0] = new wxStaticText(panel, -1, currentAnswers[0]);
		answers[1] = new wxStaticText(panel, -1, currentAnswers[1]);
		answers[2] = new wxStaticText(panel, -1, currentAnswers[2]);
		answers[3] = new wxStaticText(panel, -1, currentAnswers[3]);
		correct = currentCorrect;

		question->SetFont(font);
		answers[0]->SetFont(font);
		answers[1]->SetFont(font);
		answers[2]->SetFont(font);
		answers[3]->SetFont(font);
	}

	void QuestionFactory::Reset(wxPanel* panel, wxStaticText*& question, wxStaticText**& answers, wxString& correct)
	{
		SelectQuestionSet();
		question->SetLabel(currentQuestion);
		answers[0]->SetLabel(currentAnswers[0]);
		answers[1]->SetLabel(currentAnswers[1]);
		answers[2]->SetLabel(currentAnswers[2]);
		answers[3]->SetLabel(currentAnswers[3]);
		correct = currentCorrect;
	}

	void QuestionFactory::SelectQuestionSet()
	{
		srand(time(0));

		int randomQ = rand() % 4;
		std::string tempAnswers[4];
		int tempCorrect = 0;
		int count = 0;

		switch (randomQ)
		{
		case 0:
			currentQuestion = "what is the answer to life, the universe, and everything?";
			tempAnswers[0] = "The Void";
			tempAnswers[1] = "There is no right answer";
			tempAnswers[2] = "42";
			tempAnswers[3] = "Both A and B";
			tempCorrect = 2;
			break;
		case 1:
			currentQuestion = "What are two things you can never eat for breakfast?";
			tempAnswers[0] = "Steak and Baked Potato";
			tempAnswers[1] = "Pizza and Salad";
			tempAnswers[2] = "Candy and Ice Cream";
			tempAnswers[3] = "Lunch and Dinner";
			tempCorrect = 3;
			break;		
		case 2:
			currentQuestion = "What can be broken but never held?";
			tempAnswers[0] = "A promise";
			tempAnswers[1] = "A heart";
			tempAnswers[2] = "The universe";
			tempAnswers[3] = "The sun";
			tempCorrect = 0;
			break;		
		case 3:
			currentQuestion = "How many books can you put in an empty backpack?";
			tempAnswers[0] = "As many as it can fit";
			tempAnswers[1] = "1";
			tempAnswers[2] = "40";
			tempAnswers[3] = "200";
			tempCorrect = 1;
			break;
		}

		while(count < 4)
		{
			randomQ = rand() % 4;

			if(tempAnswers[randomQ] != "")
			{
				currentAnswers[count] = tempAnswers[randomQ];
				tempAnswers[randomQ] = "";
				if(tempCorrect == randomQ)
				{
					SetCorrectAnswer(count);
				}

				count++;
			}
		}
	}


	void QuestionFactory::SetCorrectAnswer(int correct)
	{
		switch (correct)
		{
		case 0:
			currentCorrect = "A";
			break;
		case 1:
			currentCorrect = "B";

			break;
		case 2:			
			currentCorrect = "C";
			break;
		case 3:
			currentCorrect = "D";
			break;
		}
	}

	wxButton* QuestionFactory::CreateButton(wxPanel* panel, const char* label, wxFont font)
	{
		return new wxButton(panel, wxID_ANY, label);
	}
