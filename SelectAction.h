#ifndef SELECT_ACTION_H
#define SELECT_ACTION_H


#include "Actions/Action.h"
#include "Figures/CFigure.h"

class SelectAction:public Action
{
private:
	Point p;
	CFigure* SelectedFig1;
	CFigure* PreviuosSelected;
public:
	SelectAction(ApplicationManager* pApp);

	//Reads Select parameters
	virtual void ReadActionParameters();

	//Add Select to the ApplicationManager
	virtual void Execute(bool read=true);
	bool CanBeRecorded() const;
};

#endif
