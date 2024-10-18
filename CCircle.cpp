#include "CCircle.h"
#include <fstream>
#include <istream>
#include <math.h>
#include <sstream>
#include <string>
#include<cmath>
using namespace std;

CCircle::CCircle()
{}

CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	radius = P2;
	Type = "Circle";
}
void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawCircle to draw a Circle on the screen	
	pOut->DrawCircle(Center, radius, FigGfxInfo, Selected);
}

void CCircle::change(Point p)
{
	double r = sqrt((Center.x - radius.x) * (Center.x - radius.x) + (Center.y - radius.y) * (Center.y - radius.y));
	Center.x = p.x;
	Center.y = p.y;
	radius.x = p.x + r;
	radius.y = p.y ;
}

bool CCircle::InsideMe(int x, int y)
{
	double r = sqrt((Center.x - radius.x) * (Center.x - radius.x) + (Center.y - radius.y) * (Center.y - radius.y));
	double z= sqrt((Center.x - x) * (Center.x - x) + (Center.y - y) * (Center.y - y));
	if (z>r)
	{
		return false;
	}
	return true;
}

void CCircle::Save(ofstream& OutFile)
{
	OutFile << Type << "\t" << ID << "\t" << Center.x << "\t" << Center.y << "\t" << radius.x << "\t" << radius.y << "\t";
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

void CCircle::Load(ifstream& Infile)
{
	string drw;//draw color
	string fill;//fill color
	Infile >> ID >> Center.x >> Center.y >> radius.x >> radius.y;//setting the circle corners and ID
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

void CCircle::PrintInfo(Output* pOut)
{
	double r = sqrt((Center.x - radius.x) * (Center.x - radius.x) + (Center.y - radius.y) * (Center.y - radius.y));

	string s = "Radius :";
	string s1 = std::to_string(r);
	string s2 = " ";
	string s3 = "ID= ";
	string s4 = std::to_string(ID);
	string s5 = "  Center=(";
	string s6 = std::to_string(Center.x);
	string s7 = ",";
	string s8 = std::to_string(Center.y);
	string s9 = ")";


	std::stringstream ss;
	ss << s3 << s4 << s2 << s << s1 << s2 << s5 << s6 << s7 << s8 << s9 ;
	std::string Message = ss.str();
	pOut->PrintMessage(Message);
}

Shapes CCircle::getshapetype()
{
	return circle;
}
