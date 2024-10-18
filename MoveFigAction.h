#include"Actions/Action.h"
#include"ApplicationManager.h"

class MoveFigAction:public Action
{
private:
	Point p;
	CFigure* MoveFig;
public:
	MoveFigAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool=true);
	bool CanBeRecorded() const;
};

