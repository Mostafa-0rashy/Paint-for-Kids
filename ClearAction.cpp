#include "ClearAction.h"
#include "GUI/Output.h"
#include "Figures/CFigure.h"
#include "ApplicationManager.h"

ClearAction::ClearAction(ApplicationManager* pApp) :Action(pApp)
{}

void ClearAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Clear all :");

	//Clear the status bar
	pOut->ClearStatusBar();
	pOut->ClearDrawArea(); 
}

void ClearAction::Execute(bool read)
{
	if (read)
	{
		ReadActionParameters();
	}
	pManager->ClearAll();
	Action* A = pManager->GetLastAction();
	if (pManager->IsRecording())
	{
		if (A == NULL || A->CanBeRecorded())
		{
			pManager->AddRecordAction(A);
		}
	}
}
bool ClearAction::CanBeRecorded() const
{
	return true;
}
