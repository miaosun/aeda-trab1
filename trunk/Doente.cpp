///////////////////////////////////////////////////////////
//  Doente.cpp
//  Implementation of the Class Doente
//  Created on:      24-Out-2010 20:04:09
//  Original author: Answer
///////////////////////////////////////////////////////////

#include "Doente.h"


Doente::Doente(){

}



Doente::~Doente(){

}





Doente::Doente(string nome, string dataNascimento, string tipo, string morada):Pessoa(nome, dataNascimento, tipo)
{
	this->morada = morada;
}


string Doente::imprime(){

	stringstream ss;
	ss<<"Doente:\n";
	ss<<"\\t"<<Pessoa::imprime()<<"Morada: "<<this->morada<<endl;
	return ss.str();
}


string Doente::getMorada(){

	return this->morada;
}
