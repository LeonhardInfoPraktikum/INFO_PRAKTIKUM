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
 * \class myServer
 *
 * \brief Klasse für Server; erbt TCPserver
 *
 */
class myServer : public TCPserver {

public:
	myServer(int port, int maxDataSizeRecv):TCPserver(port, maxDataSizeRecv){
		myWorld = new TASK3::World();
	};

	string myResponse(string input);

private:
	TASK3::World *myWorld;


};


#endif /* MYSERVER_H_ */
