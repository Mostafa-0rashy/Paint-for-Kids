#include "DAction.h"
#include "GUI/Output.h"
#include "Figures/CFigure.h"
#include "ApplicationManager.h"
DAction::DAction(ApplicationManager* pApp) :Action(pApp)
{
	SelectedFig = pManager->GetSelected();
}

void DAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Delete a figure:");

	//Clear the status bar
	pOut->ClearStatusBar();
	
}

void DAction::Execute(bool read)
{
	Output* pOut = pManager->GetOutput();
	if (read)
	{
		ReadActionParameters();
	}
	if (pManager->GetSelectedFigures() == NULL)
	{
		pOut->PrintMessage("Please Select a Figure First");
		return ;
	}

	pManager->DeleteFig();
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
void DAction::undo()
{
	pManager->AddFigure(SelectedFig);
}
void DAction::redo()
{
	pManager->DeleteFig();
}
bool DAction::CanBeRecorded() const
{
	return true;
}