#ifndef CCIRC_H
#define CCIRC_H

#include "Figures/CFigure.h"

class CCircle : public CFigure
{
private:
	Point Center;
	Point radius;
public:
	CCircle();
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual void change(Point p);
	virtual bool InsideMe(int x, int y) ;

	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	virtual void PrintInfo(Output* pOut);
	virtual Shapes getshapetype();
};

#endif

