#include "StopRec.h"

StopRec::StopRec(ApplicationManager* pApp):Action(pApp)
{}

void StopRec::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Stop Recording");
}

void StopRec::Execute(bool read)
{
	Output* pOut = pManager->GetOutput();
	if (read)
	{
		if (!pManager->IsRecording())
		{
			pOut->PrintMessage("Record some actions first");
			return ;
		}
		ReadActionParameters();
	}
	Action* A = pManager->GetLastAction();
	pManager->AddRecordAction(A);

	pManager->SetRecord(false);
}
bool StopRec::CanBeRecorded() const
{
	return false;
}
