#include "PlayRec.h"

PlayRec::PlayRec(ApplicationManager* pApp):Action(pApp)
{}

void PlayRec::ReadActionParameters()
{
}

void PlayRec::Execute(bool read)
{
	Output* pOut = pManager->GetOutput();
	if (pManager->IsRecording())
	{
		pOut->PrintMessage("Stop the recording first");
		return;		
	}
	if (pManager->GetRecCount() == 0)
	{	
		pOut->PrintMessage("Record some actions first");
		return;
	}
	if (pManager->IsRecording() == false && pManager->GetRecCount() != 0)
	{
		pOut->ClearDrawArea();
		pOut->ClearStatusBar();
		pManager->PlayingRec();
		return;
	}
}
bool PlayRec::CanBeRecorded() const
{
	return false;
}
