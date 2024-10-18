#include "PickByType.h"
#include "ApplicationManager.h"

PickByType::PickByType(ApplicationManager * pApp) : Action(pApp)
{
    Type =circle;  
    Max=0, 
    wrongans=0, 
    rightans=0;
}

void PickByType::ReadActionParameters()
{
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();
    pOut->PrintMessage("Pick By Type:");
}

string PickByType::ShapeToString(Shapes shape)
{
    if (Type == square)
    {
        return"Square";
    }
    if (Type==rectangle)
    {
        return"Rectangle";
    }
    if (Type == circle)
    {
        return"Circle";
    }
    if (Type == hexagon)
    {
        return"Hexagon";
    }
    if (Type == triangle)
    {
        return"Triangle";
    }
    return"";
}

void PickByType::Execute(bool read)
{

    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();
    if (pManager->getFigCount() == 0) {
        pOut->PrintMessage("No Figure Found:");
        return;
    }
    Type= pManager->getrandomtype();
    Max= pManager->getfigurecounttype(Type);

    while (true) {
        pOut->PrintMessage("Pick all " + ShapeToString(Type) + "s Incorrect: " + to_string(wrongans) + " Correct: " + to_string(rightans));

        Point p;
        pIn->GetPointClicked(p.x, p.y);

        CFigure* figure = pManager->GetFigure(p.x, p.y);
        if (figure == 0) {
            continue;
        }

        if (figure->getshapetype() == Type) {
            rightans++;
        }
        else {
            wrongans++;
        }

        
        figure->SetSelected(true);
        pManager->DeleteFig();

        pOut->ClearDrawArea();
        pManager->UpdateInterface();

        if (wrongans + rightans >= Max) {
            break;
        }
    }

    int score = (int)(rightans / (float)Max * 100);
    pOut->PrintMessage("Game over, Score=" + to_string(score) + "%");
}

bool PickByType::CanBeRecorded() const
{
    return false;
}
