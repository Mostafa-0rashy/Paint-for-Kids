#include "AddSquareAction.h"
#include "CSquare.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"

AddSquareAction::AddSquareAction(ApplicationManager* pApp) :Action(pApp)
{
	id = 0;
}

void AddSquareAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click at Center");

	//Read Center and store in point P1
	pIn->GetPointClicked(P.x, P.y);

	SquGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SquGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SquGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddSquareAction::Execute(bool read)
{
	//This action needs to read some parameters first
	if (read)
	{
		ReadActionParameters();

	}
	//Create a Square with the parameters read from the user
	CSquare* S = new CSquare(P, SquGfxInfo);
	Action* A = pManager->GetLastAction();
	//Add the Square to the list of figures
	pManager->AddF(S);
	id = S->GetID();
	if (pManager->IsRecording())
	{
		if (A == NULL || A->CanBeRecorded())
		{
			pManager->AddRecordAction(A);
		}
	}
	pManager->Addundoact(this);
	Sq = S;

}
bool AddSquareAction::CanBeRecorded() const
{
	return true;
}

void AddSquareAction::undo()
{
	Sq->SetSelected(true);
	pManager->DeleteFig();
}

void AddSquareAction::redo()
{
	Sq->SetSelected(false);
	pManager->AddFigure(Sq);

}
