#ifndef CHEX_H
#define CHEX_H

#include "Figures/CFigure.h"

class CHex : public CFigure
{
private:
	Point Center;
public:
	CHex();
	CHex(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual void change(Point P);
	virtual bool InsideMe(int x, int y);

	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	virtual void PrintInfo(Output* pOut);
	virtual Shapes getshapetype();
};

#endif