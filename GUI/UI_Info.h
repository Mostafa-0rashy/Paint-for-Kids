#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY	//Playing mode
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	//TODO: Add more items names here
	ITM_RECT,		//Recangle item in menu
	ITM_Triangle,
	ITM_Square,
	ITM_Hexagon,
	ITM_Circle,
	ITM_SelectOne,
	ITM_ChangeColorBorder,
	ITM_ChangeColorFill,

	ITM_Green,
	ITM_Black,
	ITM_Blue,
	ITM_Yellow,
	ITM_Red,
	ITM_Orange,

	ITM_Move,
	ITM_Undo,
	ITM_Redo,
	ITM_Clear,

	ITM_StartRec,
	ITM_EndRec,
	ITM_PlayRec,

	ITM_Delete,
	ITM_SaveGraph,
	ITM_LoadGraph,
	ITM_SwitchToPlayMode,
	ITM_EXIT, //Exit item

	ITM_EMPTY,
	ITM_Status,
	ITM_DrawArea,

	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here

	//TODO: Add more items names here

	ITM_PickAndHideByType,
	ITM_PickAndHideBycolor,
	ITM_PickAndHideByBoth,

	ITM_SwitchToDrawMode,
	ITM_EXIT1,
	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};



__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;

	int	width, height,	    //Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight;		//Tool Bar Height (distance from top of window to bottom line of toolbar)
	float MenuItemWidth;		//Width of each item in toolbar menu


	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed

}UI;	//create a global object UI

#endif