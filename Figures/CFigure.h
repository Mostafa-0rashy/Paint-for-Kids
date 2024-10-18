#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	bool PlayHidden;// hides figures in playmode.
	string Type;//Figure type
	
	/// Add more parameters if needed.

public:
	CFigure();
	CFigure(GfxInfo FigureGfxInfo);

	void SetSelected(bool s);	//select/unselect the figure
	virtual bool IsSelected() const;	//check whether fig is selected
	
	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	virtual void change(Point P) = 0;			//Changes the figure position
	virtual bool InsideMe(int x,int y)=0;
	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color

	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure
	color getdrawclr();
	color getfillclr();
	int GetID();
	void SetID(int id);
	GfxInfo GetGfxInfo();
	///Decide the parameters that you should pass to each function	

	//PlayBar
	void Hide();
	void Show();
	bool HiddenStatus();


	virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file
	virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
	virtual Shapes getshapetype()=0;
};

#endif