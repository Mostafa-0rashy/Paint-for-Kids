#include "CFigure.h"

CFigure::CFigure()
{}

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	FigGfxInfo.FillClr = LIGHTGOLDENRODYELLOW;
	Selected = false;
	PlayHidden = false;
}
void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}
color CFigure::getdrawclr() 
{
	return FigGfxInfo.DrawClr;
}
color CFigure::getfillclr() 
{
	return FigGfxInfo.FillClr;
}
int CFigure::GetID()
{
	return ID;
}
void CFigure::SetID(int id)
{
	ID = id;
}
GfxInfo CFigure::GetGfxInfo()
{
	return FigGfxInfo;
}
void CFigure::Hide()
{
	PlayHidden = true;
}
//Shows Figures
void CFigure::Show()
{
	PlayHidden = false;
}
//Gives Current Status
bool CFigure::HiddenStatus()
{
	return PlayHidden;
}