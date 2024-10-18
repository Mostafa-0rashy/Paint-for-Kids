#pragma once
#include "Figures/CFigure.h"
#include "Actions/Action.h"

class PickByColor : public Action
{
	CFigure* Fig;
	int  no_colors, rand_fig_no, picked_color_no, wrgSel, rigSel;
	int clrs[6];
	Point P;
public:
	color AssignColor(CFigure*);
	void PrntScore(int);
	PickByColor(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute(bool read=true);
	bool CanBeRecorded() const;
};
