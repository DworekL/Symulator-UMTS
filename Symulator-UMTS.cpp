//******************************************************************************************
//
//
//
//Autor
//L.Dworczynski  marzec 2021
//
//
//Historia zmian:
//
//Autor                       Co zmienil
//-----                       -----
//
//****************************************************************************************** 

#include <iostream>
#include "radioNetworkController.h"
#include "ue.h"
#include "windows.h"
#include <iomanip>

std::string randomizeConnectionType(); //losuje rodzaj polaczenia
int randomizeCell(); //losuje cell
std::string randomizeAction(); //losuje akcje

int main()
{
    //1 RNC
    radioNetworkController RNC;

    //2 CELL
    ue Tab_UE[30];

    for (int i = 1; i < 31; i++)
    {
        Tab_UE[i - 1].setID(i);
        Tab_UE[i - 1].setAction("");
        Tab_UE[i - 1].setCellNumber(0);
        Tab_UE[i - 1].setState("IDLE");
        Tab_UE[i - 1].setConnectionType("");
    }

    bool t = true;
    int iteracja = 0;

    //glowne iteracje
    while (t)
    {
        for (int i = 0; i < 30; i++)
        {
            if (Tab_UE[i].getState() == "IDLE")
            {
                std::string conType = randomizeConnectionType();
                int cellNumber = randomizeCell();
                std::string request = RNC.resourceRequest(cellNumber, conType, Tab_UE[i].getID());
                if (request == "resourceConfirm")
                {
                    Tab_UE[i].setState("CONNECTED");
                    Tab_UE[i].setAction("Call Establishment - CONFIRM");
                    Tab_UE[i].setCellNumber(cellNumber);
                    Tab_UE[i].setConnectionType(conType);
                }
                else if (request == "resourceReject")
                {
                    Tab_UE[i].setAction("Call Establishment - REJECTED");
                }
            }
            else //jezeli CONNECTED
            {
                std::string action = randomizeAction();
                if (action == "handover")
                {
                    int cellNumber = randomizeCell();
                    RNC.handover(Tab_UE[i].getCellNumber(), Tab_UE[i].getConnectionType(), Tab_UE[i].getID(), cellNumber); //obecny cell , obecny typ polaczenia , UE , nowy cell
                    Tab_UE[i].setAction("Handover");
                    Tab_UE[i].setCellNumber(cellNumber);
                }
                else if (action == "release")
                {
                    RNC.callRelease(Tab_UE[i].getCellNumber(), Tab_UE[i].getConnectionType(), Tab_UE[i].getID());
                    Tab_UE[i].setAction("Call Release");
                    Tab_UE[i].setState("IDLE");
                    Tab_UE[i].setCellNumber(0);
                    Tab_UE[i].setConnectionType("");
                }
            }
        }


        std::cout << "ITERATION NR." << iteracja << std::endl;
        
        std::cout << std::left;
        std::cout << std::setw(10) << "[UE ID]" << std::setw(20) << "[STATE]" << std::setw(24) << "[TYPE OF CONNECTION]" << std::setw(40) << "[LAST ACTION]" << std::setw(20) << "[CELL NUMBER]" << '\n';
        for (int i = 0; i < 30; i++)
        {
            std::cout << std::setw(10) << Tab_UE[i].getID() << std::setw(20) << Tab_UE[i].getState() << std::setw(24) << Tab_UE[i].getConnectionType() << std::setw(45) << Tab_UE[i].getAction() << std::setw(20) << Tab_UE[i].getCellNumber() << '\n';
        }
          
        Sleep(5000);
        iteracja++;
        system("CLS");
    }

    return 0;
}

std::string randomizeConnectionType()
{
    double u = (rand() / double(RAND_MAX)) * 3;

    if (u >= 0 && u <= 1)
    {
        return "PS";
    }
    if (u > 1 && u <= 2)
    {
        return "CS";
    }
    if (u > 2 && u <= 3)
    {
        return "PS-CS";
    }
}

int randomizeCell()
{
    double u = (rand() / double(RAND_MAX));
    if (u >= 0 && u <= 0.5)
    {
        return 1;
    }
    if (u > 0.5 && u < 1)
    {
        return 2;
    }
}

std::string randomizeAction()
{
    double u = (rand() / double(RAND_MAX));
    if (u >= 0 && u <= 0.5)
    {
        return "handover";
    }
    if (u > 0.5 && u < 1)
    {
        return "release";
    }
}
