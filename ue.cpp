#include "ue.h"

ue::ue()
	:
	State(""),
	ConnectionType(""),
	Action(""),
	CellNumber(0),
	ID(0)
{
}

ue::~ue()
{
}

ue::ue(std::string state, std::string cT, std::string a, int cN, int ID)
	:
	State(state),
	ConnectionType(cT),
	Action(a),
	CellNumber(cN),
	ID(ID)
{
}

std::string ue::getState()
{
	return State;
}

void ue::setState(std::string s)
{
	State = s;
}

std::string ue::getConnectionType()
{
	return ConnectionType;
}

void ue::setConnectionType(std::string cT)
{
	ConnectionType = cT;
}

std::string ue::getAction()
{
	return Action;
}

void ue::setAction(std::string a)
{
	Action = a;
}

int ue::getCellNumber()
{
	return CellNumber;
}

void ue::setCellNumber(int cN)
{
	CellNumber = cN;
}

int ue::getID()
{
	return ID;
}

void ue::setID(int id)
{
	ID = id;
}
