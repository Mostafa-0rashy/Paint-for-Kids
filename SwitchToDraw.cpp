#include "SwitchToDraw.h"
#include "ApplicationManager.h"
#include "GUI/Output.h"
#include "GUI/Input.h"


SwitchToDraw::SwitchToDraw(ApplicationManager* pApp) :Action(pApp)
{}

void SwitchToDraw::ReadActionParameters()
{}

void SwitchToDraw::Execute(bool read)
{
	//Get a Pointer to the Output Interface
	Output* pOut = pManager->GetOutput();
	if (read)
	{
		ReadActionParameters();
	}
	pOut->CreateDrawToolBar();
	pOut->PrintMessage("Switched to Draw Mode!");
}
bool SwitchToDraw::CanBeRecorded() const
{
	return false;
}
