#ifndef Clearall_ACTION_H
#define Clearall_ACTION_H

#include"ApplicationManager.h"
#include "Actions/Action.h"
#include "Figures/CFigure.h"

class ClearAction :public Action
{
private:
	Point p1,p2;
	int FigCount;
public:
	ClearAction(ApplicationManager* pApp);

	//Reads Select parameters
	virtual void ReadActionParameters();

	//Add Select to the ApplicationManager
	virtual void Execute(bool read=true);
	bool CanBeRecorded() const;
};

#endif

