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

#ifndef cell_h
#define cell_h

#include <vector>
#include <algorithm>

class cell
{

protected:

	//zmienne
	int ValueOfCS;
	int ValueOfPS;
	std::vector <int> Vector_UE;

public:

	//konstruktor i destruktor
	cell();
	virtual ~cell();

	//gettery i settery
	int getValueOfCS();
	void setValueOfCS(int cs);
	int getValueOfPS();
	void setValueOfPS(int ps);
	void addUE(int ID);
	void removeUE (int ID);
};

#endif

