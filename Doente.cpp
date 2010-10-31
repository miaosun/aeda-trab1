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


vector<string> Doente::imprime(){

	stringstream s;
	vector<string> v;
	v=Pessoa::imprime();

	s<<"   Morada: "<<this->morada;
	v.push_back(s.str());

	return v;
}


string Doente::getMorada(){

	return this->morada;
}

vector<string> Doente::editPessoa()
{
	vector<string> opcoes;
	stringstream ss;
	opcoes = Pessoa::editPessoa();

	ss<<"4 - Editar Morada: "<<this->morada;
	opcoes.push_back(ss.str());

	return opcoes;
}

void Doente::setMorada(string morada)
{
	this->morada = morada;
}

void Doente::setEspecialidade(string especialidade){}
void Doente::setVencimento(double venc){}
void Doente::setHorario(string horario){}
void Doente::setCargo(string cargo){}
