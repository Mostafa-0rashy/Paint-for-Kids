#pragma once
#include "Actions/Action.h"

class ExitAction : public Action
{
public:
	ExitAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	//Executes the switch to Play mode
	virtual void Execute(bool read=true);
	bool CanBeRecorded() const;
};

