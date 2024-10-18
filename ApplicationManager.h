#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include "Actions/Action.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 ,MaxRecCount=20, Maxundocnt = 5};	//Max no of figures};	//Max no of figures

private:
	int FigCount;//Actual number of figures
	int RecCount;
	int selectedCount;
	int WindowCount;
	int undocnt;

	CFigure* FigList[MaxFigCount];
	CFigure* Window[MaxFigCount];
	Action* RecordingList[MaxRecCount];
	CFigure* SelectedFig;	//List of all Recording (Array of pointers)
	Action* LastAction;
	Action* undoarr[Maxundocnt];
	bool Record;
	bool PlayingRecord;

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig); //Adds a new figure to the FigList
	void AddF(CFigure* pFig);
	void AddRecordAction(Action* pAction);

	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	void MoveFigure(Point p);

	void DeleteFig();
	void DeleteRecordingList();
	void ClearAll();
	void ClearRec();

	void SetSelected(CFigure* pFig);
	CFigure* GetSelected();
	CFigure** GetSelectedFigures();
	int GetSelectedCount() const;
	void ClearSelectedFigs();
	CFigure* DrawnFigs(int i) const;
	int getFigCount() const;

	void ClearWindow();
	void Load(istream& infile);
	void SaveAll(ofstream& outfile);

	bool IsRecording() const;
	Action* GetLastAction();
	void SetRecord(bool SA);
	bool GetRecord();
	int GetRecCount() const;
	void PlayingRec();
	void Addundoact(Action* pact);//Add action to undo array
	void executeundo();
	void executeredo();
	//Pick by type
	int getfigurecounttype(Shapes s);
	Shapes getrandomtype();

	// -- Interface Management Functions
	Input* GetInput() const; //Return pointer to the input
	Output* GetOutput() const;

	//Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
	void Currentdata(color& crntdraw, color& crntfill, int& count);
};

#endif