#include "RedoAction.h"
#include "UndoAction.h"
#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"

RedoAction::RedoAction(ApplicationManager* pApp) :Action(pApp)
{}
void RedoAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Redo is selected!!");
}
void RedoAction::Execute(bool read)
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
	pManager->executeredo();
}
bool RedoAction::CanBeRecorded() const
{
	return true;
}
