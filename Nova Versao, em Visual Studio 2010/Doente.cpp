///////////////////////////////////////////////////////////
//  Doente.cpp
//  Implementation of the Class Doente
//  Created on:      24-Out-2010 20:04:09
//  Original author: Answer
///////////////////////////////////////////////////////////

#include "Doente.h"


Doente::Doente(){}

Doente::~Doente(){}


Doente::Doente(string nome, string dataNascimento, string tipo, string morada):Pessoa(nome, dataNascimento, tipo)
{
	this->morada = morada;
}

string Doente::getMorada(){

	return this->morada;
}

void Doente::setMorada(string morada)
{
	this->morada = morada;
}

vector<string> Doente::imprime(){

	stringstream ss;
	vector<string> v;
	v=Pessoa::imprime();

	ss<<"   Morada: "<<this->morada;
	v.push_back(ss.str());

	return v;
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

string Doente::toString()
{
	stringstream ss;
	ss<<Pessoa::toString()<<this->morada<<"|";
	return ss.str();
}

//funcoes abstradas para objecto da superclasse consegue acessar os metodos das classes derivadas
void Doente::setEspecialidade(string especialidade){}
void Doente::setVencimento(double venc){}
void Doente::setHorario(string horario){}
void Doente::setCargo(string cargo){}
string Doente::getCargo(){return "";}
double Doente::getVencimento(){return NULL;}