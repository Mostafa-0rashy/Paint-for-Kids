#ifndef ADD_HEX_ACTION_H
#define ADD_HEX_ACTION_H

#include "Actions/Action.h"
class CHex;
//Add Hexagon Action class
class AddHexAction : public Action
{
private:
	Point P; //Square Corners
	GfxInfo HexGfxInfo;
	CHex* h1;
public:
	AddHexAction(ApplicationManager* pApp);

	//Reads Hexagon parameters
	virtual void ReadActionParameters();

	//Add Hexagon to the ApplicationManager
	virtual void Execute(bool read=true);

	bool CanBeRecorded() const;
	virtual void undo();
	virtual void redo();
};
#endif
