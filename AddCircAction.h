#ifndef ADD_CIRC_ACTION_H
#define ADD_CIRC_ACTION_H

#include "Actions/Action.h"
class CCircle;
//Add Circle Action class
class AddCircAction : public Action
{
private:
	Point P1, P2; //Circle points
	GfxInfo CircGfxInfo;
	bool record;
	CCircle* c1;
public: 
	AddCircAction(ApplicationManager* pApp);

	//Reads	Circle parameters
	virtual void ReadActionParameters();

	//Add Circle to the ApplicationManager
	virtual void Execute(bool Read=true);

	bool CanBeRecorded() const;

	void undo();

	void redo();

};

#endif