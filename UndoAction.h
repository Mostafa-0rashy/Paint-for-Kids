#ifndef UNDOACTION_H
#define UNDOACTION_H
#include "Actions\Action.h"

class UndoAction :public Action
{

public:
	UndoAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool read=true);
	bool CanBeRecorded() const;
};
#endif
