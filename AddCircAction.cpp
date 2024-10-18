#include "AddCircAction.h"
#include "CCircle.h"
#include "ApplicationManager.h"
#include "GUI/Output.h"
#include "GUI/Input.h"

AddCircAction::AddCircAction(ApplicationManager* pApp) :Action(pApp)
{
	id = 0;
}

void AddCircAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at Center point");

	//Read center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Circle: Click at a point on the radius");

	//Read point on the radius and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	CircGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	CircGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddCircAction::Execute(bool read)
{
	//This action needs to read some parameters first
	if (read)
	{
		ReadActionParameters();
	}
	//Create a Circle with the parameters read from the user
	CCircle* C = new CCircle(P1, P2, CircGfxInfo);
	Action* A = pManager->GetLastAction();
	//Add the Ciecle to the list of figures
	pManager->AddFigure(C);
	id = C->GetID();
	if (pManager->IsRecording())
	{
		if (A == NULL || A->CanBeRecorded())
		{
			pManager->AddRecordAction(A);
		}
	}
	pManager->Addundoact(this); 
	c1 = C;
}
bool AddCircAction::CanBeRecorded() const
{
	return true;
}
void AddCircAction::undo()
{
	c1->SetSelected(true);
	pManager->DeleteFig();

}
void AddCircAction::redo()
{
	c1->SetSelected(false);
	pManager->AddFigure(c1);

}
