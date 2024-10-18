#include"Actions/Action.h"
#include<string>
#include"Figures/CFigure.h"
#include"AddCircAction.h"
#include"AddHexAction.h"
#include"AddSquareAction.h"
#include"AddTriAction.h"
#include"Actions/AddRectAction.h"
class Pickbytypeandcolor:public Action
{
private:
	Shapes type;
	ActionType colors;
	int Max, wrongans, rightans;

public:
	
	string ColorToString(ActionType c);
	color AssignColor(CFigure*);
	void PrntScore(int);
	Pickbytypeandcolor(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute(bool read = true);
	bool CanBeRecorded() const;

};

