#include "cell.h"

cell::cell()
	:
	ValueOfCS(0),
	ValueOfPS(0),
	Vector_UE(NULL)
{
}

cell::~cell()
{
}


int cell::getValueOfCS()
{
	return ValueOfCS;
}

void cell::setValueOfCS(int cs)
{
	ValueOfCS = cs;
}

int cell::getValueOfPS()
{
	return ValueOfPS;
}

void cell::setValueOfPS(int ps)
{
	ValueOfPS = ps;
}

void cell::addUE(int ID)
{
	Vector_UE.push_back(ID);
}

void cell::removeUE(int ID)
{

	std::vector<int>::iterator itr = std::find(Vector_UE.begin(), Vector_UE.end(), ID);
	if (itr != Vector_UE.cend()) 
	{
		int index = std::distance(Vector_UE.begin(), itr);
		Vector_UE.erase(Vector_UE.begin() + index);
	}

}
