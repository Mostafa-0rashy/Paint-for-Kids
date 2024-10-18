#include "ExitAction.h"
#include "ApplicationManager.h"

#include "GUI/Output.h"
#include "GUI/Input.h"


ExitAction::ExitAction(ApplicationManager* pApp) : Action(pApp)
{}


void ExitAction::ReadActionParameters()
{}

//Execute action (Exit action)
void ExitAction::Execute(bool read)
{
	if (read)
	{
		ReadActionParameters();
	}
	pManager->ClearWindow();
}
bool ExitAction::CanBeRecorded() const
{
	return false;
}
