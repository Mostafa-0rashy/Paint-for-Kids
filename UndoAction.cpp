#include "UndoAction.h"
#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"

UndoAction::UndoAction(ApplicationManager* pApp):Action(pApp)
{}
void UndoAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Undo is selected!!");
}
void UndoAction::Execute(bool read)
{
	if (read)
	{
		ReadActionParameters();
	}
	//pManager->undo();
	Action* A = pManager->GetLastAction();
	if (pManager->IsRecording())
	{
		if (A == NULL || A->CanBeRecorded())
		{
			pManager->AddRecordAction(A);
		}
	}
	pManager->executeundo();
}
bool UndoAction::CanBeRecorded() const
{
	return true;
}
