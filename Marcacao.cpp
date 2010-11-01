///////////////////////////////////////////////////////////
//  Marcacao.cpp
//  Implementation of the Class Marcacao
//  Created on:      24-Out-2010 20:04:13
//  Original author: Answer
///////////////////////////////////////////////////////////

#include "Marcacao.h"


Marcacao::Marcacao(){}

Marcacao::~Marcacao(){}

int Marcacao::count = 0;

Marcacao::Marcacao(string data, string hora, string tipo){

	this->id = ++count;
	this->data = data;
	this->hora = hora;
	this->tipo = tipo;
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

string Marcacao::getTipo()
{
	return this->tipo;
}

void Marcacao::setTipo(string tipo)
{
	this->tipo = tipo;
}

int Marcacao::getId() const
{
	return this->id;
}

string Marcacao::toList()
{
	stringstream s;
	s<<"|";
	if (id<10)
		s<<" ";
	s<<this->id<<"| ";

	return s.str();
}

string Marcacao::toString()
{
	stringstream ss;
	ss<<"|"<<this->id<<"|"<<this->data<<"|"<<this->hora<<"|"<<this->tipo<<"|";
	return ss.str();
}

vector<string> Marcacao::imprime()
{
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

vector<string> Marcacao::editMarcacao()
{
	vector<string> opcoes;
	stringstream ss1,ss2,ss3;
	opcoes.push_back("Escolha o que editar:");
	opcoes.push_back("");
	ss1<<"1 - Editar data: "<<this->data;
	opcoes.push_back(ss1.str());
	ss2<<"2 - Editar Hora: "<<this->hora;
	opcoes.push_back(ss2.str());
	ss3<<"3 - Editar Tipo: "<<this->tipo;
	opcoes.push_back(ss3.str());

	return opcoes;
}

