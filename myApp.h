/*
 * myApp.h
 *
 *  Created on: 19.11.2019
 *      Author: ubuntu
 */



#ifndef MYAPP_H_
#define MYAPP_H_
#include "TASK3.H"
#include "SIMPLESOCKET.H"

/**
 *
 * \namespace my
 *
 * \brief namespace für eigene Implementierung myApp
 *
 */
namespace my {
/**
 *
 * \class myServer
 *
 * \brief Klasse für Server; erbt TCPserver
 *
 */
class myServer : public TCPserver {

public:
	myServer(int port, int maxDataSizeRecv);

	string myResponse(string input);

};


/**
 *
 * \class myApp
 *
 * \brief Klasse für Implementierung der Funktionen zur Zerstörung der Schiffe
 *
 */
class myApp {
public:
	/**
	 * \brief Länge des Spielfeldes
	 *
	 */
	int xMax = 10;
	/**
	 *
	 *
	 *
	 * \brief Höhe des Spielfeldes
	 *
	 */
	int yMax = 10;
	/**
	 *
	 * \brief anzahl der fünfer schiffe
	 *
	 */
	int fiver = 1;
	/**
	 *
	 * \brief anzahl der vierer schifffe
	 *
	 */
	int fourer = 1;
	/**
	 *
	 * \brief anzahl der dreier schifffe
	 *
	 */
	int threer = 1;
	/**
	 *
	 * \brief anzahl der zweier schifffe
	 *
	 */
	int twoer = 1;

	TASK3::World myWorld = TASK3::World(xMax, yMax, fiver, fourer, threer, twoer);

	void varianteA(){
		int x = 0;
		int y = 0;
		myWorld.printBoard();

		while(y <= yMax)
		{
			while(x <= xMax)
			{
				myWorld.shoot(x, y);
				x++;
			}
			x = 0;
			y++;
		}
		myWorld.printBoard();

	}

	void VarianteB()
	{

	}
};

} //namespace my


#endif /* MYAPP_H_ */

