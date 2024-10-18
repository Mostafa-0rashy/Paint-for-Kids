#include "CHex.h"
#include <fstream>
#include <istream>
#include <math.h>
#include <sstream>
#include <string>
#include<cmath>

CHex::CHex()
{}

CHex::CHex(Point P, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P;
	Type = "Hexagon";
}
void CHex::Draw(Output* pOut) const
{
	//Call Output::DrawHexagon to draw a Hexagon on the screen	
	pOut->DrawHexagon(Center, FigGfxInfo, Selected);
}

void CHex::change(Point P)
{
	Center.x = P.x;
	Center.y = P.y;

}

bool CHex::InsideMe(int x, int y)
{
	double r = sqrt((Center.x - x) * (Center.x - x) + (Center.y - y) * (Center.y - y));
	if (r < 70)
	{
		return true;
	}
	return false;
}

void CHex::Save(ofstream& OutFile)
{
	OutFile << Type << "\t" << ID << "\t" << Center.x << "\t" << Center.y << "\t";
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

void CHex::Load(ifstream& Infile)
{
	string drw;//draw color
	string fill;//fill color
	Infile >> ID >> Center.x >> Center.y;//setting the hexagon corners and ID
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

void CHex::PrintInfo(Output* pOut)
{
	string s1 = "ID= ";
	string s2 = std::to_string(ID);
	string s3 = " ";
	string s4 = "  Center=(";
	string s5 = std::to_string(Center.x);
	string s6 = ",";
	string s7 = std::to_string(Center.y);
	string s8 = ")";


	std::stringstream ss;
	ss << s1 << s2 << s3 << s4 << s5 << s6 << s7 << s8 ;
	std::string Message = ss.str();
	pOut->PrintMessage(Message);
}

Shapes CHex::getshapetype()
{
	return hexagon();
}

