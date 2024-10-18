#include "CRectangle.h"
#include <fstream>
#include <istream>
#include <math.h>
#include <sstream>
#include <string>
#include<cmath>

CRectangle::CRectangle()
{}

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Type = "Rectangle";
}
void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}
void CRectangle::change(Point P)
{
	 double Width = (Corner2.x - Corner1.x);
	 double Length = (Corner2.y - Corner1.y);
	
	Corner1.x = P.x;
	Corner1.y = P.y;

	Corner2.x = P.x + Width;
	Corner2.y=  P.y+ Length;
}
bool CRectangle::InsideMe(int x, int y)
{
	if (Corner1.x >= Corner2.x )
	{
		if (x<=Corner1.x && x>=Corner2.x&&y<=Corner1.y&&y>=Corner2.y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (x <= Corner2.x && x >= Corner1.x && y <= Corner2.y && y >= Corner1.y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}

void CRectangle::Save(ofstream& OutFile)
{
	OutFile << Type << "\t" << ID << "\t" << Corner1.x << "\t" << Corner1.y << "\t" << Corner2.x << "\t" << Corner2.y << "\t";
	if (FigGfxInfo.DrawClr == BLUE)
		OutFile << "Blue" << "\t";
	if (FigGfxInfo.DrawClr == ORANGE)
		OutFile << "Orange" << "\t";
	if (FigGfxInfo.DrawClr == BLACK)
		OutFile << "Black" << "\t";
	if (FigGfxInfo.DrawClr == RED)
		OutFile << "Red" << "\t";
	if (FigGfxInfo.DrawClr == YELLOW)
		OutFile << "Yellow" << "\t";
	if (FigGfxInfo.DrawClr == GREEN)
		OutFile << "Green" << "\t";
	if (FigGfxInfo.isFilled == true)
	{
		if (FigGfxInfo.FillClr == BLUE)
			OutFile << "Blue" << "\t";
		if (FigGfxInfo.FillClr == ORANGE)
			OutFile << "Orange" << "\t";
		if (FigGfxInfo.FillClr == BLACK)
			OutFile << "Black" << "\t";
		if (FigGfxInfo.FillClr == RED)
			OutFile << "Red" << "\t";
		if (FigGfxInfo.FillClr == YELLOW)
			OutFile << "Yellow" << "\t";
		if (FigGfxInfo.FillClr == GREEN)
			OutFile << "Green" << "\t";

	}
	else
	{
		OutFile << "NoFill";
	}
	OutFile << "\n";
}

void CRectangle::Load(ifstream& Infile)
{
	string drw;//draw color
	string fill;//fill color
	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y;//setting the rectangle corners and ID
	Infile >> drw;//drw=draw color now
	if (drw == "Red")
		ChngDrawClr(RED);
	if (drw == "Blue")
		ChngDrawClr(BLUE);
	if (drw == "Black")
		ChngDrawClr(BLACK);
	if (drw == "Yellow")
		ChngDrawClr(YELLOW);
	if (drw == "Orange")
		ChngDrawClr(ORANGE);
	if (drw == "Green")
		ChngDrawClr(GREEN);
	/// Set fill color of figure
	Infile >> fill;// fill=fill color
	if (fill == "NoFill")
	{
		FigGfxInfo.isFilled = false;
		ChngFillClr(LIGHTGOLDENRODYELLOW);
	}
	else
	{ 
	if (fill == "Red")
		ChngFillClr(RED);
	if (fill == "Blue")
		ChngFillClr(BLUE);
	if (fill == "Black")
		ChngFillClr(BLACK);
	if (fill == "Yellow")
		ChngFillClr(YELLOW);
	if (fill == "Orange")
		ChngFillClr(ORANGE);
	if (fill == "Green")
		ChngFillClr(GREEN);
	FigGfxInfo.isFilled = true;
	}

}
void CRectangle::PrintInfo(Output* pOut)
{
	string s1 = "ID= ";
	string s2 = std::to_string(ID);
	string s3 = " ";
	string s4 = "  Corner1=(";
	string s5 = std::to_string(Corner1.x);
	string s6 = ",";
	string s7 = std::to_string(Corner1.y);
	string s8 = ")";
	string s9 = "  Corner2=(";
	string s10 = std::to_string(Corner2.x);
	string s11 = ",";
	string s12 = std::to_string(Corner2.y);
	string s13 = ")";


	std::stringstream ss;
	ss << s1 << s2 << s3 << s4 << s5 << s6 << s7 << s8<<s3<<s9<<s10<<s11<<s12<<s13;
	std::string Message = ss.str();
	pOut->PrintMessage(Message);
}

Shapes CRectangle::getshapetype()
{
	return rectangle;
}
