#include "SaveAction.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include<fstream>
#include "GUI/Output.h"
#include "GUI/Input.h"
#include <fstream>
#include<string>
SaveAction::SaveAction(ApplicationManager* pApp) :Action(pApp)
{}
void SaveAction::ReadActionParameters()
{
	//Get the file name to be saved
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Enter The Filename");
	myfile = pIn->GetSrting(pOut);

}
void SaveAction::Execute(bool read)
{
	//This action needs to read some parameters first
	if (read)
	{
		ReadActionParameters();
	}
	ofstream outFile(myfile + ".txt", ios::out);
	pManager->Currentdata(draw, fill, cnt);
	//output draw color
	if (draw == BLUE)
		outFile << "Blue" << "\t";
	if (draw == ORANGE)
		outFile << "Orange" << "\t";
	if (draw == BLACK)
		outFile << "Black" << "\t";
	if (draw == RED)
		outFile << "Red" << "\t";
	if (draw == YELLOW)
		outFile << "Yellow" << "\t";
	if (draw == BLACK)
		outFile << "Black" << "\t";
	if (draw == GREEN)
		outFile << "Green" << "\t";
	//output fill color
	if (fill == BLUE)
		outFile << "Blue" << "\t";
	if (fill == ORANGE)
		outFile << "Orange" << "\t";
	if (fill == BLACK)
		outFile << "Black" << "\t";
	if (fill == RED)
		outFile << "Red" << "\t";
	if (fill == YELLOW)
		outFile << "Yellow" << "\t";
	if (fill == BLACK)
		outFile << "Black" << "\t";
	if(fill == GREEN)
		outFile << "Black" << "\t";
	outFile << "\n" << cnt << "\n";
	pManager->SaveAll(outFile);
	outFile.close();
	Action* A = pManager->GetLastAction();
	if (pManager->IsRecording())
	{
		if (A == NULL || A->CanBeRecorded())
		{
			pManager->AddRecordAction(A);
		}
	}
}
bool SaveAction::CanBeRecorded() const
{
	return false;
}