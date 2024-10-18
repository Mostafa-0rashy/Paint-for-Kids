#include "StartRec.h"
#include"ClearAction.h"


StartRec::StartRec(ApplicationManager* pApp): Action(pApp)
{}

void StartRec::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Recording has started");
}

void StartRec::Execute(bool read)
{
	Output* pOut = pManager->GetOutput();
	Action* A = pManager->GetLastAction();
	ClearAction* PClear = dynamic_cast<ClearAction*>(A) ;
	if (read)
	{
		if ((A == NULL) || (PClear != NULL))
		{
			pManager->SetRecord(true);
			ReadActionParameters();
		}
		else
		{
			pOut->PrintMessage("Cannot Record: ");
			pManager->SetRecord(false);
		}	
	}
	if (pManager->IsRecording())
	{
		if  (A == NULL || A->CanBeRecorded())
		{
			pManager->AddRecordAction(A);
		}
	}
}
bool StartRec::CanBeRecorded() const
{
	return false;
}

