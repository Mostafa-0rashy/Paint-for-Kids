#include "Output.h"
#define _USE_MATH_DEFINES
#include <math.h>


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;

	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy = 5;


	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 47.8;

	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames


	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");

	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	Point p1, p2;
	p1.x = 0;
	p1.y = 0;
	p2.x = UI.width;
	p2.y = UI.ToolBarHeight;
	GfxInfo RectGfxInfo;
	RectGfxInfo.DrawClr = WHITE;
	RectGfxInfo.FillClr = WHITE;
	RectGfxInfo.isFilled = true;
	RectGfxInfo.BorderWdth = 8;
	DrawRect(p1, p2, RectGfxInfo, false);


	string MenuItemImages[DRAW_ITM_COUNT];
	//TODO: Prepare images for each menu item and add it to the list

	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_Triangle] = "images\\MenuItems\\Menu_Tri.jpg";
	MenuItemImages[ITM_Square] = "images\\MenuItems\\Menu_Square.jpg";
	MenuItemImages[ITM_Hexagon] = "images\\MenuItems\\Menu_Hex.jpg";
	MenuItemImages[ITM_SelectOne] = "images\\MenuItems\\Menu_Select.jpg";
	MenuItemImages[ITM_Circle] = "images\\MenuItems\\Menu_Circ.jpg";
	MenuItemImages[ITM_ChangeColorBorder] = "images\\MenuItems\\Menu_ChangeColorBorder.jpg";
	MenuItemImages[ITM_ChangeColorFill] = "images\\MenuItems\\Menu_ChangeColorFill.jpg";
	MenuItemImages[ITM_Green] = "images\\MenuItems\\Menu_Green.jpg";
	MenuItemImages[ITM_Black] = "images\\MenuItems\\Menu_Black.jpg";
	MenuItemImages[ITM_Blue] = "images\\MenuItems\\Menu_Blue.jpg";
	MenuItemImages[ITM_Yellow] = "images\\MenuItems\\Menu_Yellow.jpg";
	MenuItemImages[ITM_Red] = "images\\MenuItems\\Menu_Red.jpg";
	MenuItemImages[ITM_Orange] = "images\\MenuItems\\Menu_Orange.jpg";
	MenuItemImages[ITM_Move] = "images\\MenuItems\\Menu_Move.jpg";
	MenuItemImages[ITM_Undo] = "images\\MenuItems\\Menu_Undo.jpg";
	MenuItemImages[ITM_Redo] = "images\\MenuItems\\Menu_Redo.jpg";
	MenuItemImages[ITM_Clear] = "images\\MenuItems\\Menu_Clear.jpg";
	MenuItemImages[ITM_StartRec] = "images\\MenuItems\\Menu_StartRec.jpg";
	MenuItemImages[ITM_EndRec] = "images\\MenuItems\\Menu_EndRec.jpg";
	MenuItemImages[ITM_PlayRec] = "images\\MenuItems\\Menu_PlayRec.jpg";
	MenuItemImages[ITM_Delete] = "images\\MenuItems\\Menu_Delete.jpg";
	MenuItemImages[ITM_SaveGraph] = "images\\MenuItems\\Menu_Save.jpg";
	MenuItemImages[ITM_LoadGraph] = "images\\MenuItems\\Menu_LoadGraph.jpg";
	MenuItemImages[ITM_SwitchToPlayMode] = "images\\MenuItems\\Menu_ToPlay.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	//Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT - 3; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	Point p1, p2;
	p1.x = 0;
	p1.y = 0;
	p2.x = UI.width;
	p2.y = UI.ToolBarHeight;
	GfxInfo RectGfxInfo;
	RectGfxInfo.DrawClr = WHITE;
	RectGfxInfo.FillClr = WHITE;
	RectGfxInfo.isFilled = true;
	RectGfxInfo.BorderWdth = 8;
	DrawRect(p1, p2, RectGfxInfo, false);
	///TODO: write code to create Play mode menu
	string PlayMenuItem[PLAY_ITM_COUNT];

	PlayMenuItem[ITM_PickAndHideByType] = "images\\MenuItems\\Menu_PickAndHideByType.jpg";
	PlayMenuItem[ITM_PickAndHideBycolor] = "images\\MenuItems\\Menu_PickAndHideByColor.jpg";
	PlayMenuItem[ITM_PickAndHideByBoth] = "images\\MenuItems\\Menu_PickAndHideByBoth.jpg";
	PlayMenuItem[ITM_SwitchToDrawMode] = "images\\MenuItems\\Menu_ToDraw.jpg";
	PlayMenuItem[ITM_EXIT1] = "images\\MenuItems\\Menu_Exit.jpg";
	//Draw menu item one image at a time
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(PlayMenuItem[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}

void Output::DrawCircle(Point p1, Point p2, GfxInfo CircleGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = CircleGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (CircleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircleGfxInfo.FillClr);
	}
	else
		style = FRAME;

	int r = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));

	pWind->DrawCircle(p1.x, p1.y, r, style);

}

void Output::DrawTriangle(Point p1, Point p2, Point p3, GfxInfo TriGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TriGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (TriGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(p1.x, p1.y, p2.x, p2.y, p3.x, p3.y, style);
}

void Output::DrawHexagon(Point p, GfxInfo HexGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = HexGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (HexGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(HexGfxInfo.FillClr);
	}
	else
		style = FRAME;
	double HexWdth = 70;
	const int Px[6] = { p.x - HexWdth ,p.x - HexWdth * cos(M_PI / 3),p.x + HexWdth * cos(M_PI / 3),p.x + HexWdth,p.x + HexWdth * cos(M_PI / 3),p.x - HexWdth * cos(M_PI / 3) };
	const int Py[6] = { p.y,p.y - HexWdth * sin(M_PI / 3),p.y - HexWdth * sin(M_PI / 3),p.y,p.y + HexWdth * sin(M_PI / 3),p.y + HexWdth * sin(M_PI / 3) };
	pWind->DrawPolygon(Px, Py, 6, style);
}

void Output::DrawSquare(Point p, GfxInfo SquareGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = SquareGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (SquareGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(SquareGfxInfo.FillClr);
	}
	else
		style = FRAME;

	double SquareLength = 70;
	Point P1, P2;
	P1.x = p.x - SquareLength; P1.y = p.y - SquareLength;
	P2.x = p.x + SquareLength; P2.y = p.y + SquareLength;

	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
}


//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

