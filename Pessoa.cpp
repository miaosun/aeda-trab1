///////////////////////////////////////////////////////////
//  Pessoa.cpp
//  Implementation of the Class Pessoa
//  Created on:      24-Out-2010 20:04:15
///////////////////////////////////////////////////////////

#include "Pessoa.h"


Pessoa::Pessoa(){

}



Pessoa::~Pessoa(){

}



Pessoa::Pessoa(string nome, string dataNascimento, string tipo){

	this->nome = nome;
	this->dataNascimento = dataNascimento;
	this->tipo = tipo;
}


string Pessoa::getName(){

	return  this->nome;
}

void Pessoa::setName(string nome)
{
	this->nome = nome;
}

string Pessoa::getDataNascimento(){

	return  this->dataNascimento;
}

void Pessoa::setDataNascimento(string dataNascimento)
{
	this->dataNascimento = dataNascimento;
}

int Pessoa::getId()
{
	return this->id;
}

vector<string> Pessoa::imprime(){
/*
	stringstream ss;
	ss<<"Nome: "<<this->nome<<"\nData de Nascimento: "<<this->dataNascimento<<"\nTipo: "<<tipo<<endl;
	return ss.str();*/

	vector<string> v;
	stringstream s1, s2, s3, s4;

	s1<<"ID: "<<this->id;
	v.push_back(s1.str());

	s2<<"Nome: "<<this->nome;
	v.push_back(s2.str());

	s3<<"Data de Nascimento: "<<this->dataNascimento;
	v.push_back(s3.str());

	s4<<"Tipo: "<<this->tipo;
	v.push_back(s4.str());

	return v;
}


string Pessoa::getTipo(){

	return  this->tipo;
}


void Pessoa::setTipo(string tipo){
	this->tipo = tipo;
}
