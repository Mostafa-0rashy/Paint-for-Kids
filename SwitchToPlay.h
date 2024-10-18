#pragma once
#include "Actions/Action.h"

class SwitchToPlay: public Action 
{
public:

	SwitchToPlay(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	//Executes the switch to Play mode
	virtual void Execute(bool read=true);
	bool CanBeRecorded() const;
};

