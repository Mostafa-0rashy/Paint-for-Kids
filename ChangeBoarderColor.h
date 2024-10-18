#include".\Actions\Action.h"
#include"Figures/CFigure.h"
#include"ApplicationManager.h"
class ChangeBoarderColor :public Action
{
protected:
	ActionType incolor;
public:
	ChangeBoarderColor(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool read=true);
	bool CanBeRecorded() const;
};


