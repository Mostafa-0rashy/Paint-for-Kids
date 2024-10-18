#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_RECT,		//Draw Rectangle
	DRAW_CIRCLE, // Draw a circle
	DRAW_TRI,  // Draw a triangle
	DRAW_SQU, //Draw a square
	DRAW_HEX, //Draw a hexagon

	ChangeColorFill,
	ChangeColorBorder,
	Black,
	Blue,
	Yellow,
	Red,
	Orange,
	Green,

	Select_one,
	Move,
	Undo,
	Redo,
	Clear,

	StartRecording,
	EndRec,
	PlayRecording,

	Delete,
	SaveGraph,
	LoadGraph,
	TO_PLAY,		//Switch interface to Play mode

	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,	//A click on the drawing area
	STATUS,	//A click on the status bar

	PickAndHideByType,
	PickAndHideByColor,
	PickAndHidetByBoth,
	TO_DRAW,	//Switch interface to Draw mode
	EXIT,		//Exit
	///TODO: Add the other action types of the two modes
};
enum Shapes
{
	hexagon,
	triangle,
	rectangle,
	square,
	circle,
};
struct Point	//To be used for figures points
{
	int x, y;
};

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif