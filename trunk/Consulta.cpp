///////////////////////////////////////////////////////////
//  Consulta.cpp
//  Implementation of the Class Consulta
//  Created on:      24-Out-2010 20:04:07
//  Original author: Answer
///////////////////////////////////////////////////////////

#include "Consulta.h"


Consulta::Consulta(){

}



Consulta::~Consulta(){

}





Consulta::Consulta(string data, string hora, string tipo):Marcacao(data, hora, tipo)
{

}


vector<string> Consulta::imprime(){
/*
	stringstream ss;
	ss<<"Consulta:\n";
	ss<<"\\t"<<Marcacao::imprime();
	return ss.str();*/

	vector<string> v;

	v=Marcacao::imprime();

	return v;
}
