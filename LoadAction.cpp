#include "LoadAction.h"
#include"GUI/Output.h"
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include<fstream>
#include "GUI/Output.h"
#include "GUI/Input.h"
#include <istream>
#include "CTriangle.h"
#include "Figures/CFigure.h"
#include "Figures/CRectangle.h"
#include "CCircle.h"
#include"CTriangle.h"
#include "CHex.h"
#include"CSquare.h"
LoadAction::LoadAction(ApplicationManager* pApp) :Action(pApp)
{}
void LoadAction::ReadActionParameters()
{
	//Get the saved file name
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Enter The Filename");
	myfile = pIn->GetSrting(pOut);

}

void LoadAction::Execute(bool read)
{
	if (read)
	{
		ReadActionParameters();
	}
	pManager->ClearAll();
	string draw; //draw color
	string fill;// fill color
	int cnt; // count of figures
	string type; //figure type
	CFigure* myfig = NULL;//figure to be drawn
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ifstream Infile;
	Infile.open(myfile + ".txt", ios::in);
	if (Infile.fail()) //if file name is invaild
	{
		pOut->PrintMessage("Invalid file name");
		return;
	}
	else
		pOut->PrintMessage("Valid file name");
	Infile >> draw;//reads draw clr
	Infile >> fill; //reads fill clr
	////////////Set draw color
	if (draw == "Red")
		UI.DrawColor = RED;
	if (draw == "Blue")
		UI.DrawColor = BLUE;
	if (draw == "Yellow")
		UI.DrawColor = YELLOW;
	if (draw == "Black")
		UI.DrawColor = BLACK;
	if (draw == "Orange")
		UI.DrawColor = ORANGE;
	if (draw == "Green")
		UI.DrawColor = GREEN;
	////////////Set fill color
	if (fill == "Red")
		UI.FillColor = RED;
	if (fill == "Blue")
		UI.FillColor = BLUE;
	if (fill == "Yellow")
		UI.FillColor = YELLOW;
	if (fill == "Black")
		UI.FillColor = BLACK;
	if (fill == "Orange")
		UI.FillColor = ORANGE;
	if (fill == "Green")
		UI.FillColor = GREEN;
	if (fill == "No fill")
		UI.FillColor = WHITE;
	//// Read fig count
	Infile >> cnt;
	//identify figures
	for (int i = 0; i < cnt; i++)
	{
		Infile >> type;
		if (type == "Rectangle")
			myfig = new CRectangle;
		if (type == "Circle")
			myfig = new CCircle;
		if (type == "Triangle")
			myfig = new CTriangle;
		if (type == "Square")
			myfig = new CSquare;
		if (type == "Hexagon")
			myfig = new CHex;
		myfig->Load(Infile);
		pManager->AddF(myfig);
	}
}
bool LoadAction::CanBeRecorded() const
{
	return false;
}