#include".\Actions\Action.h"
#include"Figures/CFigure.h"
#include"ApplicationManager.h"
class CFigure;
class ChangeFillColor :public Action
{
protected:
	ActionType fillcolor;
	color crntclr;
	CFigure* colr;
public:
	ChangeFillColor(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool read=true);
	bool CanBeRecorded() const;
	virtual void undo();
	virtual void redo();
};

