#include "SelectAction.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"

SelectAction::SelectAction(ApplicationManager* pApp) :Action(pApp)
{}

void SelectAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select a figure: Click a figure");

	//Read clicked point and store in P
	pIn->GetPointClicked(p.x, p.y);

	//Clear the status bar
	pOut->ClearStatusBar();
}
void SelectAction::Execute(bool read)
{
	//Reads the point that the user clicked
	if (read)
	{
		ReadActionParameters();
	}
	//Set SelectedFig to the clicked figure (if any)
	SelectedFig1 = pManager->GetFigure(p.x, p.y);

	Output* pOut = pManager->GetOutput();
	PreviuosSelected = pManager->GetSelected();
	
	if (PreviuosSelected == NULL && SelectedFig1 != NULL)
	{
		SelectedFig1->SetSelected(true);
		pManager->SetSelected(SelectedFig1);
		SelectedFig1->PrintInfo(pOut);
	}
	else if (PreviuosSelected != NULL && SelectedFig1 != NULL && PreviuosSelected != SelectedFig1)
	{
		SelectedFig1->SetSelected(true);
		PreviuosSelected->SetSelected(false);
		pManager->SetSelected(SelectedFig1);
		SelectedFig1->PrintInfo(pOut);
	}
	else if (PreviuosSelected == NULL && SelectedFig1 == NULL)
	{
		pOut->PrintMessage("Error!Select a figure");
	}
	else if (PreviuosSelected != NULL && SelectedFig1 != NULL && PreviuosSelected == SelectedFig1)
	{
		SelectedFig1->SetSelected(false);
		pManager->SetSelected(NULL);
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
bool SelectAction::CanBeRecorded() const
{
	return true;
}


