#pragma once
#include "wx/wx.h"

class Window;

class QuizMaster : public wxApp
{
	Window* window = nullptr;

public:
	virtual bool OnInit();
};

