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





Marcacao::Marcacao(string data, string hora, string tipo){

	this->data = data;
	this->hora = hora;
	this->tipo = tipo;
}


vector<string> Marcacao::imprime(){

	/*stringstream ss;
	ss<<"Data: "<<data<<"\nHora: "<<hora<<endl;
	return ss.str();*/

	vector<string> v;
	stringstream s;

	s<<this->tipo<<":\n";
	v.push_back(s.str());

	s<<"\tData: "<<this->data;
	v.push_back(s.str());

	s<<"\tHora: "<<this->hora;
	v.push_back(s.str());

	return v;
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
