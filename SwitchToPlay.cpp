#include "SwitchToPlay.h"
#include "ApplicationManager.h"
#include "GUI/Output.h"
#include "GUI/Input.h"


SwitchToPlay::SwitchToPlay(ApplicationManager* pApp) :Action(pApp)
{}

void SwitchToPlay::ReadActionParameters()
{}

void SwitchToPlay::Execute(bool read)
{
	//Get a Pointer to the Output Interface
	Output* pOut = pManager->GetOutput();
	if (read)
	{
		ReadActionParameters();
	}
	pOut->CreatePlayToolBar();
	pOut->PrintMessage("Switched to Play Mode!");
}
bool SwitchToPlay::CanBeRecorded() const
{
	return false;
}
