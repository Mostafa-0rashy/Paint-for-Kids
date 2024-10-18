#pragma once
#include "Actions/Action.h"

class SwitchToDraw : public Action
{
public:
	
	SwitchToDraw(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	//Executes the switch to draw mode
	virtual void Execute(bool read=true);
	bool CanBeRecorded() const;
};

