#include "radioNetworkController.h"

radioNetworkController::radioNetworkController()
{
}

radioNetworkController::~radioNetworkController()
{
}

std::string radioNetworkController::resourceRequest(int cellNumber, std::string conType, int id)
{
	if (conType == "CS")
	{
		if (Tab_Cell[cellNumber-1].getValueOfCS() < 3 && Tab_Cell[cellNumber - 1].getValueOfCS() >= 0)
		{
			Tab_Cell[cellNumber - 1].setValueOfCS(Tab_Cell[cellNumber - 1].getValueOfCS() + 1);
			Tab_Cell[cellNumber - 1].addUE(id);
			return "resourceConfirm";
		}
		else
		{
			return "resourceReject";
		}
	}
	else if (conType == "PS")
	{
		if (Tab_Cell[cellNumber-1].getValueOfPS() < 5 && Tab_Cell[cellNumber - 1].getValueOfPS() >= 0)
		{
			Tab_Cell[cellNumber - 1].setValueOfPS(Tab_Cell[cellNumber - 1].getValueOfPS() + 1);
			Tab_Cell[cellNumber - 1].addUE(id);
			return "resourceConfirm";
		}
		else
		{
			return "resourceReject";
		}
	}
	else //jezeli PS-CS
	{
		if (Tab_Cell[cellNumber - 1].getValueOfPS() < 5 && Tab_Cell[cellNumber - 1].getValueOfCS() < 3 && Tab_Cell[cellNumber - 1].getValueOfCS() >= 0 && Tab_Cell[cellNumber - 1].getValueOfPS() >= 0)
		{
			Tab_Cell[cellNumber - 1].setValueOfCS(Tab_Cell[cellNumber - 1].getValueOfCS() + 1);
			Tab_Cell[cellNumber - 1].setValueOfPS(Tab_Cell[cellNumber - 1].getValueOfPS() + 1);
			Tab_Cell[cellNumber - 1].addUE(id);
			return "resourceConfirm";
		}
		else
		{
			return "resourceReject";
		}
	}
	
}

void radioNetworkController::handover(int oldCellNumber, std::string conType, int id, int newCellNumber) //obecny cell , obecny typ polaczenia , UE , nowy cell
{
	//usuwanie ue ze starej komórki
	Tab_Cell[oldCellNumber-1].removeUE(id);
	if (conType == "CS")
	{
		if (Tab_Cell[oldCellNumber - 1].getValueOfCS() <= 3 && Tab_Cell[oldCellNumber - 1].getValueOfCS() > 0)
		{
			Tab_Cell[oldCellNumber - 1].setValueOfCS(Tab_Cell[oldCellNumber - 1].getValueOfCS() - 1);
		}
		if (Tab_Cell[oldCellNumber - 1].getValueOfCS() == -1)
		{
			Tab_Cell[oldCellNumber - 1].setValueOfCS(3);
		}
		if (Tab_Cell[oldCellNumber - 1].getValueOfCS() < -1)
		{
			Tab_Cell[oldCellNumber - 1].setValueOfCS(Tab_Cell[oldCellNumber - 1].getValueOfCS() + 1);
		}
	}
	else if (conType == "PS")
	{
		if (Tab_Cell[oldCellNumber - 1].getValueOfPS() <= 5 && Tab_Cell[oldCellNumber - 1].getValueOfPS() > 0)
		{
			Tab_Cell[oldCellNumber - 1].setValueOfPS(Tab_Cell[oldCellNumber - 1].getValueOfPS() - 1);
		}
		if (Tab_Cell[oldCellNumber - 1].getValueOfPS() == -1)
		{
			Tab_Cell[oldCellNumber - 1].setValueOfPS(3);
		}
		if (Tab_Cell[oldCellNumber - 1].getValueOfPS() < -1)
		{
			Tab_Cell[oldCellNumber - 1].setValueOfPS(Tab_Cell[oldCellNumber - 1].getValueOfPS() + 1);
		}
	}
	else //jezeli PS-CS
	{
		if (Tab_Cell[oldCellNumber - 1].getValueOfCS() <= 3 && Tab_Cell[oldCellNumber - 1].getValueOfCS() > 0)
		{
			Tab_Cell[oldCellNumber - 1].setValueOfCS(Tab_Cell[oldCellNumber - 1].getValueOfCS() - 1);
		}
		if (Tab_Cell[oldCellNumber - 1].getValueOfCS() == -1)
		{
			Tab_Cell[oldCellNumber - 1].setValueOfCS(3);
		}
		if (Tab_Cell[oldCellNumber - 1].getValueOfCS() < -1)
		{
			Tab_Cell[oldCellNumber - 1].setValueOfCS(Tab_Cell[oldCellNumber - 1].getValueOfCS() + 1);
		}
		if (Tab_Cell[oldCellNumber - 1].getValueOfPS() <= 5 && Tab_Cell[oldCellNumber - 1].getValueOfPS() > 0)
		{
			Tab_Cell[oldCellNumber - 1].setValueOfPS(Tab_Cell[oldCellNumber - 1].getValueOfPS() - 1);
		}
		if (Tab_Cell[oldCellNumber - 1].getValueOfPS() == -1)
		{
			Tab_Cell[oldCellNumber - 1].setValueOfPS(3);
		}
		if (Tab_Cell[oldCellNumber - 1].getValueOfPS() < -1)
		{
			Tab_Cell[oldCellNumber - 1].setValueOfPS(Tab_Cell[oldCellNumber - 1].getValueOfPS() + 1);
		}
	}

	//dodawanie ue do nowej komórki
	Tab_Cell[newCellNumber-1].addUE(id);

	if (conType == "CS")
	{
		if (Tab_Cell[newCellNumber - 1].getValueOfCS() < 3 && Tab_Cell[newCellNumber - 1].getValueOfCS() >= 0)
		{
			Tab_Cell[newCellNumber - 1].setValueOfCS(Tab_Cell[newCellNumber - 1].getValueOfCS() + 1);
		}
		if (Tab_Cell[newCellNumber - 1].getValueOfCS() == 3)
		{
			Tab_Cell[newCellNumber - 1].setValueOfCS(-1);
		}
		if (Tab_Cell[newCellNumber - 1].getValueOfCS() <= -1)
		{
			Tab_Cell[newCellNumber - 1].setValueOfCS(Tab_Cell[newCellNumber - 1].getValueOfCS() - 1);
		}
	}
	else if (conType == "PS")
	{
		if (Tab_Cell[newCellNumber - 1].getValueOfPS() < 5 && Tab_Cell[newCellNumber - 1].getValueOfPS() > 0)
		{
			Tab_Cell[newCellNumber - 1].setValueOfPS(Tab_Cell[newCellNumber - 1].getValueOfPS() - 1);
		}
		if (Tab_Cell[newCellNumber - 1].getValueOfPS() == 5)
		{
			Tab_Cell[newCellNumber - 1].setValueOfPS(-1);
		}
		if (Tab_Cell[newCellNumber - 1].getValueOfPS() < -1)
		{
			Tab_Cell[newCellNumber - 1].setValueOfPS(Tab_Cell[newCellNumber - 1].getValueOfPS() - 1);
		}
	}
	else //jezeli PS-CS
	{
		if (Tab_Cell[newCellNumber - 1].getValueOfCS() < 3 && Tab_Cell[newCellNumber - 1].getValueOfCS() >= 0)
		{
			Tab_Cell[newCellNumber - 1].setValueOfCS(Tab_Cell[newCellNumber - 1].getValueOfCS() + 1);
		}
		if (Tab_Cell[newCellNumber - 1].getValueOfCS() == 3)
		{
			Tab_Cell[newCellNumber - 1].setValueOfCS(-1);
		}
		if (Tab_Cell[newCellNumber - 1].getValueOfCS() <= -1)
		{
			Tab_Cell[newCellNumber - 1].setValueOfCS(Tab_Cell[newCellNumber - 1].getValueOfCS() - 1);
		}
		if (Tab_Cell[newCellNumber - 1].getValueOfPS() < 5 && Tab_Cell[newCellNumber - 1].getValueOfPS() > 0)
		{
			Tab_Cell[newCellNumber - 1].setValueOfPS(Tab_Cell[newCellNumber - 1].getValueOfPS() - 1);
		}
		if (Tab_Cell[newCellNumber - 1].getValueOfPS() == 5)
		{
			Tab_Cell[newCellNumber - 1].setValueOfPS(-1);
		}
		if (Tab_Cell[newCellNumber - 1].getValueOfPS() < -1)
		{
			Tab_Cell[newCellNumber - 1].setValueOfPS(Tab_Cell[newCellNumber - 1].getValueOfPS() - 1);
		}
	}
}

void radioNetworkController::callRelease(int cellNumber, std::string conType, int id)
{
	Tab_Cell[cellNumber-1].removeUE(id);
	if (conType == "CS")
	{
		if (Tab_Cell[cellNumber - 1].getValueOfCS() <= 3 && Tab_Cell[cellNumber - 1].getValueOfCS() > 0)
		{
			Tab_Cell[cellNumber - 1].setValueOfCS(Tab_Cell[cellNumber - 1].getValueOfCS() - 1);
		}
		if (Tab_Cell[cellNumber - 1].getValueOfCS() == -1)
		{
			Tab_Cell[cellNumber - 1].setValueOfCS(3);
		}
		if (Tab_Cell[cellNumber - 1].getValueOfCS() < -1)
		{
			Tab_Cell[cellNumber - 1].setValueOfCS(Tab_Cell[cellNumber - 1].getValueOfCS() + 1);
		}
	}
	else if (conType == "PS")
	{
		if (Tab_Cell[cellNumber - 1].getValueOfPS() <= 5 && Tab_Cell[cellNumber - 1].getValueOfPS() > 0)
		{
			Tab_Cell[cellNumber - 1].setValueOfPS(Tab_Cell[cellNumber - 1].getValueOfPS() - 1);
		}
		if (Tab_Cell[cellNumber - 1].getValueOfPS() == -1)
		{
			Tab_Cell[cellNumber - 1].setValueOfPS(3);
		}
		if (Tab_Cell[cellNumber - 1].getValueOfPS() < -1)
		{
			Tab_Cell[cellNumber - 1].setValueOfPS(Tab_Cell[cellNumber - 1].getValueOfPS() + 1);
		}
	}
	else //jezeli PS-CS
	{
		if (Tab_Cell[cellNumber - 1].getValueOfCS() <= 3 && Tab_Cell[cellNumber - 1].getValueOfCS() > 0)
		{
			Tab_Cell[cellNumber - 1].setValueOfCS(Tab_Cell[cellNumber - 1].getValueOfCS() - 1);
		}
		if (Tab_Cell[cellNumber - 1].getValueOfCS() == -1)
		{
			Tab_Cell[cellNumber - 1].setValueOfCS(3);
		}
		if (Tab_Cell[cellNumber - 1].getValueOfCS() < -1)
		{
			Tab_Cell[cellNumber - 1].setValueOfCS(Tab_Cell[cellNumber - 1].getValueOfCS() + 1);
		}
		if (Tab_Cell[cellNumber - 1].getValueOfPS() <= 5 && Tab_Cell[cellNumber - 1].getValueOfPS() > 0)
		{
			Tab_Cell[cellNumber - 1].setValueOfPS(Tab_Cell[cellNumber - 1].getValueOfPS() - 1);
		}
		if (Tab_Cell[cellNumber - 1].getValueOfPS() == -1)
		{
			Tab_Cell[cellNumber - 1].setValueOfPS(3);
		}
		if (Tab_Cell[cellNumber - 1].getValueOfPS() < -1)
		{
			Tab_Cell[cellNumber - 1].setValueOfPS(Tab_Cell[cellNumber - 1].getValueOfPS() + 1);
		}
	}
}
