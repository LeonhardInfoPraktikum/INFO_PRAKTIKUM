/*
 * myServer.c
 *
 *  Created on: 07.01.2020
 *      Author: ubuntu
 */


#include "myServer.h"



string myServer::myResponse(string input){
		std::stringstream ss;
		int x,y;
		TASK3::ShootResult result;

		if(input.compare(0,6,"COORD[") == 0){
			if(2!=sscanf(input.c_str(),"COORD[%d,%d]",&x,&y)){
				return string("RES[-2]");
			}
			if( (x<1) || (y<1) || (x>10) || (y>10) ){
				return string ("RES[-2]");
			}
			result = (TASK3::ShootResult) (rand()%6);
			ss << "RES[" << result << "]";
			return ss.str();
		};

		if(input.compare(0,7,"NEWGAME") == 0){
			return string ("OK");
		};

		return (string ("UNKNOWN"));
	}




