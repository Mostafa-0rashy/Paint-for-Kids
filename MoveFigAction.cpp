#include "MoveFigAction.h"

MoveFigAction::MoveFigAction(ApplicationManager* pApp) :Action(pApp)
{}

void MoveFigAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Select a place to move the figure");
	pIn->GetPointClicked(p.x, p.y);
	pOut->ClearStatusBar();

}

void MoveFigAction::Execute(bool read)
{
	Output* pOut = pManager->GetOutput();
	if (read)
	{
		ReadActionParameters();
	}

	if (pManager->GetSelectedFigures() == NULL)
	{
		pOut->PrintMessage("Please Select a Figure First");
		return;
	}
	pManager->MoveFigure(p);
	Action* A = pManager->GetLastAction();
	if (pManager->IsRecording())
	{
		if (A == NULL || A->CanBeRecorded())
		{
			pManager->AddRecordAction(A);
		}
	}
}
bool MoveFigAction::CanBeRecorded() const
{
	return true;
}