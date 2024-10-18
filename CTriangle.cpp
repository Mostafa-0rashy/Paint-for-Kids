#include "CTriangle.h"
#include <fstream>
#include <istream>
#include <math.h>
#include <sstream>
#include <string>
#include<cmath>

CTriangle::CTriangle()
{}

CTriangle::CTriangle(Point P1, Point P2, Point P3,GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
	Type = "Triangle";
}

void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTriangle to draw a Triangle on the screen	
	pOut->DrawTriangle(Corner1, Corner2,Corner3, FigGfxInfo, Selected);
}
float area(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}


bool CTriangle::InsideMe(int x, int y)
{
	double A = area(Corner1.x, Corner1.y, Corner2.x, Corner2.y, Corner3.x, Corner3.y);
	double A1 = area(x, y, Corner2.x, Corner2.y, Corner3.x, Corner3.y);
	double A2 = area(Corner1.x, Corner1.y, x, y, Corner3.x, Corner3.y);
	double A3 = area(Corner1.x, Corner1.y, Corner2.x, Corner2.y, x, y);
	if (A == A1 + A2 + A3)
	{
		return true;
	}
	return false;
}

void CTriangle::change(Point P)
{
	Point C;
	C.x = (Corner1.x + Corner2.x + Corner3.x) / 3;
	C.y = (Corner1.y + Corner2.y + Corner3.y) / 3;
	double Diffx = P.x - C.x;
	double Diffy = P.y - C.y;
	Corner1.x += Diffx;
	Corner1.y += Diffy;
	Corner2.x += Diffx;
	Corner2.y += Diffy;
	Corner3.x += Diffx;
	Corner3.y += Diffy;
}
void CTriangle::Save(ofstream& OutFile)
{
	OutFile << Type << "\t" << ID << "\t" << Corner1.x << "\t" << Corner1.y << "\t" << Corner2.x << "\t" << Corner2.y << "\t" << Corner3.x << "\t" << Corner3.y << "\t";
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

void CTriangle::Load(ifstream& Infile)
{
	string drw;//draw color
	string fill;//fill color
	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> Corner3.x >> Corner3.y;//setting the triangle corners and ID
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

void CTriangle::PrintInfo(Output* pOut)
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
	string s14 = "  Corner3=(";
	string s15 = std::to_string(Corner3.x);
	string s16 = ",";
	string s17 = std::to_string(Corner3.y);
	string s18 = ")";


	std::stringstream ss;
	ss << s1 << s2 << s3 << s4 << s5 << s6 << s7 << s8 << s3 << s9 << s10 << s11 << s12 << s13<<s3<<s14<<s15<<s16<<s17<<s18;
	std::string Message = ss.str();
	pOut->PrintMessage(Message);
}

Shapes CTriangle::getshapetype()
{
	return triangle;
}

