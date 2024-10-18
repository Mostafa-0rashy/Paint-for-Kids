#ifndef STOP_REC_H
#define STOP_REC_H

#include "Actions/Action.h"
#include "Figures/CFigure.h"
#include "ApplicationManager.h"

class StopRec :public Action
{
public:
	StopRec(ApplicationManager* pApp);

	//Reads  parameters
	virtual void ReadActionParameters();

	//Add Select to the ApplicationManager
	virtual void Execute(bool read);
	bool CanBeRecorded() const;
};

#endif

