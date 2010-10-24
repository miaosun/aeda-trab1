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


string Pessoa::getDataNascimento(){

	return  this->dataNascimento;
}


string Pessoa::imprime(){

	stringstream ss;
	ss<<"Nome: "<<this->nome<<"\nData de Nascimento: "<<this->dataNascimento<<"\nTipo: "<<tipo<<endl;
	return ss.str();
}


string Pessoa::getTipo(){

	return  this->tipo;
}


void Pessoa::setTipo(string tipo){
	this->tipo = tipo;
}
