#ifndef START_REC_H
#define START_REC_H

#include "Actions/Action.h"
#include "Figures/CFigure.h"
#include "ApplicationManager.h"

class StartRec :public Action
{
public:
	StartRec(ApplicationManager* pApp);

	//Reads Select parameters
	virtual void ReadActionParameters();

	//Add Select to the ApplicationManager
	virtual void Execute(bool read);
	bool CanBeRecorded() const;
};

#endif

