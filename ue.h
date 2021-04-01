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

#ifndef ue_h
#define ue_h
#include <string>

class ue
{

protected:

	//zmienne
	std::string State; 
	std::string ConnectionType;
	std::string Action;
	int CellNumber;
	int ID;

public:

	//konstruktory i destruktor
	ue();
	virtual ~ue();
	ue(std::string state, std::string cT, std::string a, int cN, int ID);

	//gettery i settery
	std::string getState();
	void setState(std::string s);
	std::string getConnectionType();
	void setConnectionType(std::string cT);
	std::string getAction();
	void setAction(std::string a);
	int getCellNumber();
	void setCellNumber(int cN);
	int getID();
	void setID(int id);
};

#endif

