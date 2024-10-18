#include"Actions/Action.h"
#include"Figures/CFigure.h"

class DAction:public Action
{
private:
	CFigure* SelectedFig;
	Point p;

public:
	DAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool read=true);
	virtual void undo();
	virtual void redo();
	bool CanBeRecorded() const;
};