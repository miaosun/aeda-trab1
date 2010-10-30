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





Exame::Exame(string data, string hora, string tipo, string sala):Marcacao(data, hora, tipo)
{
	this->sala = sala;
}


string Exame::getSala(){

	return this->sala;
}


void Exame::setSala(){

	this->sala = sala;
}


vector<string> Exame::imprime(){
/*
	stringstream ss;
	ss<<"Exame:\n";
	ss<<"\\t"<<Marcacao::imprime()<<"Sala: "<<sala<<endl;
	return ss.str();*/

	vector<string> v;
	stringstream s;

	v=Marcacao::imprime();

	s<<"   Sala: "<<this->sala;
	v.push_back(s.str());

	return v;
}
