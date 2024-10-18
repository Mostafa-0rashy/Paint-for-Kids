#include "AddTriAction.h"
#include "CTriangle.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"

AddTriAction::AddTriAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddTriAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first corner");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Triangle: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	pOut->PrintMessage("New Triangle: Click at Third corner");
	//Read 3rd corner and store in point P3
	pIn->GetPointClicked(P3.x, P3.y);

	TriGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	TriGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddTriAction::Execute(bool read)
{
	//This action needs to read some parameters first
	if (read)
	{
		ReadActionParameters();
	}

	//Create a Triangle with the parameters read from the user
	CTriangle* T = new CTriangle(P1, P2, P3, TriGfxInfo);
	Action* A = pManager->GetLastAction();
	//Add the Triangle to the list of figures
	pManager->AddFigure(T);
	id = T->GetID();
	if (pManager->IsRecording())
	{
		if (A == NULL || A->CanBeRecorded())
		{
			pManager->AddRecordAction(A);
		}
	}
	pManager->Addundoact(this);
	tri = T;
}
bool AddTriAction::CanBeRecorded() const
{
	return true;
}

void AddTriAction::undo()
{
	tri->SetSelected(true);
	pManager->DeleteFig();
}

void AddTriAction::redo()
{
	tri->SetSelected(false);
	pManager->AddFigure(tri);
}
