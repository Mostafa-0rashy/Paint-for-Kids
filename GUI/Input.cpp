#include "Input.h"
#include "Output.h"


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output* pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if ((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECT;
			case ITM_EXIT: return EXIT;
			case ITM_Circle: return DRAW_CIRCLE;
			case ITM_Triangle: return DRAW_TRI;
			case ITM_Square: return DRAW_SQU;
			case ITM_Hexagon: return DRAW_HEX;
			case ITM_SelectOne: return Select_one;
			case ITM_ChangeColorFill: return ChangeColorFill;
			case ITM_ChangeColorBorder:return ChangeColorBorder;
			case ITM_Move: return Move;
			case ITM_Undo: return Undo;
			case ITM_Redo: return Redo;
			case ITM_Clear: return Clear;
			case ITM_StartRec: return StartRecording;
			case ITM_EndRec: return EndRec;
			case ITM_PlayRec: return PlayRecording;
			case ITM_SaveGraph: return SaveGraph;
			case ITM_LoadGraph: return LoadGraph;
			case ITM_Delete: return Delete;
			case ITM_SwitchToPlayMode: return TO_PLAY;
			case ITM_EMPTY: return EMPTY;
			case ITM_Status: return STATUS;
			case ITM_DrawArea:return DRAWING_AREA;
			case ITM_Orange: return Orange;
			case ITM_Blue: return Blue;
			case ITM_Yellow:return Yellow;
			case ITM_Red: return Red;
			case ITM_Black:return Black;
			case ITM_Green:return Green;
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action

		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_PickAndHideByType:return PickAndHideByType;
			case ITM_PickAndHideBycolor:return PickAndHideByColor;
			case ITM_PickAndHideByBoth:return PickAndHidetByBoth;
			case ITM_SwitchToDrawMode: return TO_DRAW;
			case ITM_EXIT1:return EXIT;
			default:return EMPTY;	//just for now. This should be updated
			}

		}
		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
		/////////////////////////////////
	}
}
Input::~Input()
{

}
