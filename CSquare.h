#ifndef CSQU_H
#define CSQU_H

#include "Figures/CFigure.h"

class CSquare : public CFigure
{
private:
	Point Center;
public:
	CSquare();
	CSquare(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual void change(Point P);
	bool InsideMe(int x, int y);

	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	virtual void PrintInfo(Output* pOut);
	virtual Shapes getshapetype();
};

#endif