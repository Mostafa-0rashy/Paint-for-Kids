#pragma once
#include "Actions/Action.h"
class SaveAction :public Action
{
private:
	string myfile;
	color draw;
	color fill;
	int cnt;
public:
	SaveAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool read=true);
	bool CanBeRecorded() const;
};
