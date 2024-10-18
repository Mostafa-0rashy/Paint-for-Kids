#include "AddHexAction.h"
#include "CHex.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"

AddHexAction::AddHexAction(ApplicationManager* pApp) :Action(pApp)
{
	id = 0;
}

void AddHexAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Hex: Click at Center");

	//Read Center and store in point P1
	pIn->GetPointClicked(P.x, P.y);

	HexGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	HexGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddHexAction::Execute(bool read)
{
	//This action needs to read some parameters first
	if (read)
	{
		ReadActionParameters();
	}
	
	//Create a Hexagon with the parameters read from the user
	CHex* H = new CHex(P, HexGfxInfo);
	Action* A = pManager->GetLastAction();
	//Add the Hexagon to the list of figures
	pManager->AddF(H);
	id = H->GetID();
	if (pManager->IsRecording())
	{
		if (A == NULL || A->CanBeRecorded())
		{
			pManager->AddRecordAction(A);
		}
	}
	pManager->Addundoact(this);
	h1 = H;
}
bool AddHexAction::CanBeRecorded() const
{
	return true;
}

void AddHexAction::undo()
{

	h1->SetSelected(true);
	pManager->DeleteFig();
}

void AddHexAction::redo()
{
	h1->SetSelected(false);
	pManager->AddFigure(h1);
}
