#ifndef ADD_SQU_ACTION_H
#define ADD_SQU_ACTION_H

#include "Actions/Action.h"
class CSquare;
//Add Square Action class
class AddSquareAction : public Action
{
private:
	Point P; //Square Corners
	GfxInfo SquGfxInfo;
	CSquare* Sq;
public:
	AddSquareAction(ApplicationManager* pApp);

	//Reads Square parameters
	virtual void ReadActionParameters();

	//Add Square to the ApplicationManager
	virtual void Execute(bool read=true);

	bool CanBeRecorded() const;
	virtual void undo();
	virtual void redo();
};
#endif