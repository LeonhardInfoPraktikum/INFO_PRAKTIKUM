/*
 * myClient.c
 *
 *  Created on: 08.01.2020
 *      Author: ubuntu
 */





#include <string>
#include <iostream>
#include <sstream>
#include <unistd.h>
#include "SIMPLESOCKET.H"
#include <time.h>
#include <stdlib.h>
#include "TASK3.H"

using namespace std;


int varianteA(TCPclient *ptrC);
int varianteB(TCPclient *ptrC);


int main()
{
	srand(time(NULL));
	int nmbShoots;
	TCPclient c;
	string host = "localhost";

	c.conn(host , 2024);

	cout << "Durchlauf aller Felder:" << endl;

	for(int i=0; i < 20; i++){
		nmbShoots = varianteA(&c);
		cout << nmbShoots << endl;
	}
	cout << "Zufällige Koordinaten:" << endl;
	for(int i=0; i < 20; i++){
		nmbShoots = varianteB(&c);
		cout << nmbShoots << endl;
	}

}


int varianteB(TCPclient *ptrC)
{
	stringstream *strStream = NULL;
	string msg;
	int counter = 0;
	int r;
	int x;

	ptrC->sendData(string("NEWGAME"));
	msg = ptrC->receive(32);


	while (msg.compare(0,5,"RES[4") != 0)
	{



		if(strStream != NULL)
		{
			delete strStream;
		}

		int x = (rand() % 10)+1;

		int y = (rand() % 10)+1;

		strStream = new stringstream();
		*strStream << "COORD["<<x<<","<<y<<"]";
		ptrC->sendData(strStream->str());
		msg = ptrC -> receive(32);
		counter++;
	}


return counter;
}

int varianteA(TCPclient *ptrC)
{
	stringstream *strStream = NULL ;
	string msg;
	int x = 1;
	int y = 1;
	int counter = 0;
	int r,s;


	ptrC->sendData(string("NEWGAME")); //startet neues spiel
	msg = ptrC->receive(32);			//erwartet antwoRT

	while (y <= 10)
	{

		while (x <= 10)
		{

			if(strStream != NULL)
			{
				delete strStream;
			}

			strStream = new stringstream();
			*strStream << "COORD["<<x<<","<<y<<"]";
			ptrC->sendData(strStream->str());
			msg = ptrC -> receive(32);

			x++;

			if ( 1 == sscanf(msg.c_str(), "RES[%d]", &r))
			{
				counter++;
			}

			else
			{
				cout << "unbekannt:" << msg << endl;
			}

			if (r == TASK3::GAME_OVER)
			{
				break;
			};

		}
		if (r == TASK3::GAME_OVER)
		{
			break;
		};

		y++;
		x = 1;
	}
	return counter;
}
