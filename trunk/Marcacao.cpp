///////////////////////////////////////////////////////////
//  Marcacao.cpp
//  Implementation of the Class Marcacao
//  Created on:      24-Out-2010 20:04:13
//  Original author: Answer
///////////////////////////////////////////////////////////

#include "Marcacao.h"


Marcacao::Marcacao(){

}



Marcacao::~Marcacao(){

}





Marcacao::Marcacao(string data, string hora){

	this->data = data;
	this->hora = hora;
}


string Marcacao::imprime(){

	stringstream ss;
	ss<<"Data: "<<data<<"\nHora: "<<hora<<endl;
	return ss.str();
}


string Marcacao::getData(){

	return  this->data;
}


void Marcacao::setData(string data){
	this->data = data;
}


string Marcacao::getHora(){

	return  this->hora;
}


void Marcacao::setHora(string hora){

	this->hora = hora;
}

int Marcacao::getId() const
{
	return this->id;
}
