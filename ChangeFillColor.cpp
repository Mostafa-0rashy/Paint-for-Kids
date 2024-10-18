#include "ChangeFillColor.h"
#include "ApplicationManager.h"
#include "GUI/Output.h"
#include "GUI/Input.h"
ChangeFillColor::ChangeFillColor(ApplicationManager* pApp) :Action(pApp)
{}
void ChangeFillColor::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Choose a color");
	fillcolor = pIn->GetUserAction();
	pOut->ClearStatusBar();
}
void ChangeFillColor::Execute(bool read)
{
	if (read)
	{
		ReadActionParameters();
	}

	Output* pOut = pManager->GetOutput();
	CFigure* col = pManager->GetSelected();
	colr = col;
	crntclr=col->getfillclr();
	if (col == NULL)
	{
		return ;
	}
	
	else
	{
		if (fillcolor == Black)
		{
			col->ChngFillClr(BLACK);
		}
		else if (fillcolor == Red)
		{
			col->ChngFillClr(RED);
		}
		else if (fillcolor == Orange)
		{
			col->ChngFillClr(ORANGE);
		}
		else if (fillcolor == Yellow)
		{
			col->ChngFillClr(YELLOW);
		}
		else if (fillcolor == Blue)
		{
			col->ChngFillClr(BLUE);
		}
		else if (fillcolor == Green)
		{
			col->ChngFillClr(GREEN);
		}
	}
	Action* A = pManager->GetLastAction();
	if (pManager->IsRecording())
	{
		if (A == NULL || A->CanBeRecorded())
		{
			pManager->AddRecordAction(A);
		}
	}
	pManager->Addundoact(this);
}
bool ChangeFillColor::CanBeRecorded() const
{
	return true;
}

void ChangeFillColor::undo()
{
	colr->ChngFillClr(crntclr);
}
void ChangeFillColor::redo()
{
	if (fillcolor == Black)
	{
		colr->ChngFillClr(BLACK);
	}
	else if (fillcolor == Red)
	{
		colr->ChngFillClr(RED);
	}
	else if (fillcolor == Orange)
	{
		colr->ChngFillClr(ORANGE);
	}
	else if (fillcolor == Yellow)
	{
		colr->ChngFillClr(YELLOW);
	}
	else if (fillcolor == Blue)
	{
		colr->ChngFillClr(BLUE);
	}
	else if (fillcolor == Green)
	{
		colr->ChngFillClr(GREEN);
	};
}

