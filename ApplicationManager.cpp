#include "ApplicationManager.h"
#include"Figures/CFigure.h"
#include "Actions\AddRectAction.h"
#include "AddCircAction.h"
#include "AddTriAction.h"
#include "AddSquareAction.h"
#include "AddHexAction.h"
#include "SelectAction.h"
#include "ChangeFillColor.h"
#include"ChangeBoarderColor.h"
#include "DAction.h"
#include"MoveFigAction.h"
#include"UndoAction.h"
#include"RedoAction.h"
#include "ClearAction.h"
#include "SwitchToDraw.h"
#include"SwitchToPlay.h"
#include "ExitAction.h"
#include"PickByColor.h"
#include "SaveAction.h"
#include "LoadAction.h"
#include "StartRec.h"
#include "StopRec.h"
#include "PlayRec.h"
#include<string>
#include<string.h>
#include <fstream>
#include <istream>
#include<vector>
#include"PickByType.h"
//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
	RecCount = 0;
	selectedCount = 0;
	WindowCount = 0;

	SelectedFig = NULL;
	LastAction = NULL;
	Record = false;
	undocnt = 0;
	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
	{
		FigList[i] = NULL;
	}
	for (int i = 0; i < 20; i++)
	{
		RecordingList[i] = NULL;
	}
	for (int i = 0; i < Maxundocnt; i++)
		undoarr[i] = NULL;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
			//Making the tool bars
		case TO_DRAW:
			pAct = new SwitchToDraw(this);
			break;
		case TO_PLAY:
			pAct = new SwitchToPlay(this);
			break;
			//Drawing shapes
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;
		case DRAW_CIRCLE:
			pAct = new AddCircAction(this);
			break;
		case DRAW_TRI:
			pAct = new AddTriAction(this);
			break;
		case DRAW_SQU:
			pAct = new AddSquareAction(this);
			break;
		case DRAW_HEX:
			pAct = new AddHexAction(this);
			break;
			//Operations
		case Select_one:
			pAct = new SelectAction(this);
			break;
		case Delete:
			pAct = new DAction(this);
			break;
		case Move:
			pAct = new MoveFigAction(this);
			break;
		case Undo:
			pAct = new UndoAction(this);
			break;
		case Redo:
			pAct = new RedoAction(this);
			break;
		case Clear:
			pAct = new ClearAction(this);
			break;
			//Recording
		case StartRecording:
			pAct = new StartRec(this);
			break;
		case EndRec:
			pAct = new StopRec(this);
			break;
		case PlayRecording:
			pAct = new PlayRec(this);
			break;
			//Graphs
		case SaveGraph:
			pAct = new SaveAction(this);
			break;
		case LoadGraph:
			pAct = new LoadAction(this);
			break;
			//Colors
		case ChangeColorFill:
			pAct = new ChangeFillColor(this);
			break;
		case ChangeColorBorder:
			pAct = new ChangeBoarderColor(this);
			break;
			//Playbar
		case PickAndHideByType:
			pAct = new PickByType(this);
			break;
		case PickAndHideByColor:
			pAct = new PickByColor(this);
			break;
		case PickAndHidetByBoth:
			pOut->PrintMessage("Action : Pick and Hide by type and color,Click anywhere");
			break;
			/////////////////////
		case DRAWING_AREA:
			pOut->PrintMessage("Action: a click on the Drawing Area, Click anywhere");
			break;
		case EMPTY:
			pOut->PrintMessage("Action: a click on empty area in the Design Tool Bar, Click anywhere");
			break;
		///create ExitAction here
		case EXIT:
			pAct = new ExitAction(this);
			break;
		//a click on the status bar ==> no action
		case STATUS:	
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute(true);//Execute
		
		LastAction =  pAct;	//You may need to change this line depending to your implementation
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount) {
		FigList[FigCount] = pFig;
		if (SelectedFig != NULL)
		{
			FigList[FigCount]->ChngDrawClr(SelectedFig->getdrawclr());
			FigList[FigCount]->ChngFillClr(SelectedFig->getfillclr());
			FigList[FigCount]->SetID(FigCount);
		}
	}
	FigCount++;
}
void ApplicationManager::AddF(CFigure* pFig)
{
	if (FigCount < MaxFigCount) {

		FigList[FigCount] = pFig;
		FigList[FigCount]->SetID(FigCount);
	}
	FigCount++;
}
////////////////////////////////////////////////////////////////////////////////////
//Delete a figure from the list
void ApplicationManager::DeleteFig()
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected())
		{
			pOut->PrintMessage("deleted");
			for (int j= i; j < FigCount; j++)
			{
				FigList[j] = FigList[j + 1];
			}
			i--;
			FigCount--;
		}
	}
	pOut->ClearDrawArea();
	pOut->ClearStatusBar();
}
void ApplicationManager::ClearAll()
{
	for (int i = 0; i < FigCount; i++)
	{
		pOut->PrintMessage("Clear");
		for (int j = i; j < FigCount; j++)
		{
			FigList[j] = FigList[j + 1];
		}
		i--;
		FigCount--;
	}
	pOut->ClearDrawArea();
	pOut->ClearStatusBar();
}
void ApplicationManager::MoveFigure(Point p)
{
	CFigure *pFig=NULL;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected())
		{
			pFig = FigList[i];
			FigList[i] = NULL;
			FigList[i] = FigList[FigCount - 1];
			FigCount--;
			pFig->change(p);
			DeleteFig();
			AddF(pFig);
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->InsideMe(x,y)) 
		{
			return FigList[i];
		}
	}
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
}
void ApplicationManager::SaveAll(ofstream& outfile)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] != NULL)
		{
			FigList[i]->SetID(i);
			FigList[i]->Save(outfile);
		}
	}
}
void ApplicationManager::Load(istream& infile)
{
	LoadAction load(this);
}
//==============================================================================//
//								Recording functions								//
//==============================================================================//
void ApplicationManager::AddRecordAction(Action* pAction)
{
	if (RecCount < MaxRecCount) 
	{
		RecordingList[RecCount] = pAction;
	}
	RecCount++;
}
bool ApplicationManager::IsRecording() const
{
	return Record;
}
int ApplicationManager::GetRecCount()const
{
	return RecCount;
}
void ApplicationManager::PlayingRec()
{
	pOut->PrintMessage("Playing Recording");
	for (int i = 1; i < RecCount; i++)
	{
		RecordingList[i]->Execute(false);
		Sleep(1000);
	}
}
void ApplicationManager::DeleteRecordingList()
{
	for (int i = 0; i < RecCount; i++)
	{
		for (int j = i; j < FigCount; j++)
		{
			RecordingList[j] = RecordingList[j + 1];
		}
		i--;
		RecCount--;
	}
	pOut->ClearDrawArea();
	pOut->ClearStatusBar();
}
//Add undoaction to array
void ApplicationManager::Addundoact(Action* pact)
{
	if (undocnt < Maxundocnt)
	{
		undoarr[undocnt] = pact;
		undocnt++;
	}
	else if (undocnt >= Maxundocnt)
	{
		undocnt = 5;
	//	for (int i = 0; i++; i < 4)
		//	undoarr[i] = undoarr[i++];
		undoarr[0] = undoarr[1]; undoarr[1] = undoarr[2]; undoarr[2] = undoarr[3]; undoarr[3] = undoarr[4];
			undoarr[4] = pact;
	}
}
//execute undo
void ApplicationManager::executeundo()
{
	undocnt = undocnt - 1;
	if (undoarr[undocnt] == 0) {
		pOut->PrintMessage("No Actions");
	}
	else
	{
		undoarr[undocnt]->undo();
	}

}
void ApplicationManager::executeredo()
{
	
	if (undoarr[undocnt] == 0) {
		pOut->PrintMessage("No Actions");
	}
	else
	{
		undoarr[undocnt]->redo();
		undocnt++;
	}
	
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
void ApplicationManager::Currentdata(color& crntdraw, color& crntfill, int& count)    //gets current
{
	crntfill = pOut->getCrntDrawColor();
	crntdraw = pOut->getCrntDrawColor();
	count = FigCount;

}
Action* ApplicationManager::GetLastAction()
{
	return LastAction;
}
void ApplicationManager::SetRecord(bool SA)
{
	Record = SA;
}
bool ApplicationManager::GetRecord()
{
	return Record;
}
void ApplicationManager::SetSelected(CFigure* pFig)
{
	SelectedFig=pFig;
}
CFigure* ApplicationManager::GetSelected()
{
	return SelectedFig;
}
int ApplicationManager::GetSelectedCount() const
{
	return selectedCount;
}
CFigure** ApplicationManager::GetSelectedFigures()
{
	return FigList;
}
CFigure* ApplicationManager::DrawnFigs(int i) const
{
	return FigList[i];
}
int ApplicationManager::getFigCount() const
{
	return FigCount;
}
void ApplicationManager::ClearSelectedFigs() 
{
	for (int i = 0; i < selectedCount; i++)
	{ 
		FigList[i] = NULL;
	}
	selectedCount = 0;
}
void ApplicationManager::ClearWindow()
{
	if (Window != NULL)
		for (int i = 0; i < WindowCount; i++)
		{
			delete Window[i];
			pOut->PrintMessage("Action: EXIT, Program is finished");
			Window[i] = NULL;
		}
}
int ApplicationManager::getfigurecounttype(Shapes s)
{
	int count = 0;
	for (int i = 0; i < getFigCount(); i++)
	{
		if (FigList[i]->getshapetype() == s)
		count++;
	}
	return count;
}
Shapes ApplicationManager::getrandomtype()
{
	vector<Shapes> v;

	for (int i = 0; i < FigCount; i++)
	{
		v.push_back(FigList[i]->getshapetype());
	}
	return v[rand() % v.size()];
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}