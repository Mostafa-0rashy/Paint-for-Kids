#include "Pickbytypeandcolor.h"
#include"ApplicationManager.h"
string Pickbytypeandcolor::ColorToString(ActionType c)
{


	return "s";
}

color Pickbytypeandcolor::AssignColor(CFigure*)
{
	return color();
}

void Pickbytypeandcolor::PrntScore(int)
{

}

Pickbytypeandcolor::Pickbytypeandcolor(ApplicationManager* pApp):Action(pApp)
{
	type = circle;
	colors = Red;
	Max, wrongans, rightans=0;
}

void Pickbytypeandcolor::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Pick By Type and color:");
}

void Pickbytypeandcolor::Execute(bool read)
{
}

bool Pickbytypeandcolor::CanBeRecorded() const
{
	return false;
}
