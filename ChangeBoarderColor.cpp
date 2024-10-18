#include "ChangeBoarderColor.h"
#include "ApplicationManager.h"
#include "GUI/Output.h"
#include "GUI/Input.h"

ChangeBoarderColor::ChangeBoarderColor(ApplicationManager* pApp) :Action(pApp)
{}

void ChangeBoarderColor::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Choose a color");

	incolor = pIn->GetUserAction();
	pOut->ClearStatusBar();

}

void ChangeBoarderColor::Execute(bool read)
{
	if (read)
	{
		ReadActionParameters();
	}
	
	Output* pOut = pManager->GetOutput();
	CFigure* col = pManager->GetSelected();
	if (col == NULL)
	{
		return ;
	}
	else
	{
		if (incolor == Black)
		{
			col->ChngDrawClr(BLACK);
		}
		else if (incolor == Red)
		{
			col->ChngDrawClr(RED);
		}
		else if (incolor == Orange)
		{
			col->ChngDrawClr(ORANGE);
		}
		else if (incolor == Yellow)
		{
			col->ChngDrawClr(YELLOW);
		}
		else if (incolor == Blue)
		{
			col->ChngDrawClr(BLUE);
		}
		else if (incolor == Green)
		{
			col->ChngDrawClr(GREEN);
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
}
bool ChangeBoarderColor::CanBeRecorded() const
{
	return true;
}