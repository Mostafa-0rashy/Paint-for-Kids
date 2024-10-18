#pragma once

#include "Actions/Action.h"
#include <string>

class PickByType : public Action
{
private:
	Shapes Type;
	int Max, wrongans, rightans;

public:
	PickByType(ApplicationManager* pApp);
	string ShapeToString(Shapes shape);
	virtual void ReadActionParameters();
	virtual void Execute(bool read=true);

	// Inherited via Action
	virtual bool CanBeRecorded() const override;
};
