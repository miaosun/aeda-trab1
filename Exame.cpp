///////////////////////////////////////////////////////////
//  Exame.cpp
//  Implementation of the Class Exame
//  Created on:      24-Out-2010 20:04:10
//  Original author: Answer
///////////////////////////////////////////////////////////

#include "Exame.h"


Exame::Exame(){

}



Exame::~Exame(){

}





Exame::Exame(string data, string hora, string sala):Marcacao(data, hora)
{
	this->sala = sala;
}


string Exame::getSala(){

	return this->sala;
}


void Exame::setSala(){

	this->sala = sala;
}


string Exame::imprime(){

	stringstream ss;
	ss<<"Exame:\n";
	ss<<"\\t"<<Marcacao::imprime()<<"Sala: "<<sala<<endl;
	return ss.str();
}
