#pragma once
#include "Actions/Action.h"
class LoadAction :public Action
{
private:
	string myfile;
public:
	LoadAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool read=true);
	bool CanBeRecorded() const;
};

