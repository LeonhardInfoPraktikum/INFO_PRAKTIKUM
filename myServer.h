/*
 * myServer.h
 *
 *  Created on: 07.01.2020
 *      Author: ubuntu
 */

#ifndef MYSERVER_H_
#define MYSERVER_H_
#include <iostream>
#include <sstream>
#include <string>
#include "SIMPLESOCKET.H"
#include "TASK3.H"

/**
 *
 * \file myServer.h
 *
 * \brief Beinhaltet Klasse myServer
 *
 */

/**
 *
 * \class myServer
 *
 * \brief Klasse für Server; erbt TCPserver
 *
 */
class myServer : public TCPserver {

public:
	/**
	 *
	 * \brief Konstruktor myServer
	 *
	 * ruft Konstruktor von TCPserver auf
	 *
	 */
	myServer(int port, int maxDataSizeRecv):TCPserver(port, maxDataSizeRecv){
		myWorld = new TASK3::World();
	};
	/**
	 *
	 * \brief Bekommt Koordinate, schießt, und sendet RES[...] zurück
	 *
	 */
	string myResponse(string input);

private:
	TASK3::World *myWorld;


};


#endif /* MYSERVER_H_ */
