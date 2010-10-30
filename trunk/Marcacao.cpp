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
	stringstream s1,s2,s3;

	s1<<this->tipo<<":";
	v.push_back(s1.str());

	s2<<"   Data: "<<this->data;
	v.push_back(s2.str());

	s3<<"   Hora: "<<this->hora;
	v.push_back(s3.str());

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
