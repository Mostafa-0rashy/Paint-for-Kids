#ifndef PLAY_REC_H
#define PLAY_REC_H

#include "Actions/Action.h"
#include "Figures/CFigure.h"
#include "ApplicationManager.h"

class PlayRec :public Action
{
public:
	PlayRec(ApplicationManager* pApp);

	//Reads  parameters
	virtual void ReadActionParameters();

	//Add Select to the ApplicationManager
	virtual void Execute(bool read);
	bool CanBeRecorded() const;
};

#endif

