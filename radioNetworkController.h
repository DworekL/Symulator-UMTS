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

#ifndef radioNetworkController_h
#define radioNetworkController_h

#include "cell.h"
#include <string>

class radioNetworkController
{

protected:

	//zmienne
	cell Tab_Cell[2];
	
public:

	//konstruktor i destruktor
	radioNetworkController();
	virtual ~radioNetworkController();

	//funkcje 
	std::string resourceRequest(int cellNumber, std::string conType, int id);
	void handover(int oldCellNumber, std::string conType, int id, int newCellNumber);
	void callRelease(int cellNumber, std::string conType, int id);


};

#endif
