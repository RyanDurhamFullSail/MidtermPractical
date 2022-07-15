#include "QuizMaster.h"
#include "Window.h"

wxIMPLEMENT_APP(QuizMaster);

bool QuizMaster::OnInit()
{
	window = new Window();
	window->Show();
	return true;
}