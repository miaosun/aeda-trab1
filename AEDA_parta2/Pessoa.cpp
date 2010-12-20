///////////////////////////////////////////////////////////
//  Pessoa.cpp
//  Implementation of the Class Pessoa
//  Created on:      24-Out-2010 20:04:15
///////////////////////////////////////////////////////////

#include "Pessoa.h"

int Pessoa::count = 0;

Pessoa::Pessoa(){}

Pessoa::~Pessoa(){--count;}
/*
Pessoa::Pessoa(int id, string nome, string dataNascimento, string tipo)
{
	this->id = id;
	this->nome = nome;
	this->dataNascimento = dataNascimento;
	this->tipo = tipo;
}*/

Pessoa::Pessoa(string nome, string dataNascimento, string tipo){

	this->id = ++count;
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

string Pessoa::getTipo(){

	return  this->tipo;
}

void Pessoa::setTipo(string tipo){
	this->tipo = tipo;
}

int Pessoa::getId()
{
	return this->id;
}

void Pessoa::setId(int id)
{
	this->id = id;
}

vector<string> Pessoa::imprime()
{
	vector<string> v;
	stringstream s1, s2, s3, s4;

	s1<<this->tipo<<":";
	v.push_back(s1.str());

	s2<<"   ID: "<<this->id;
	v.push_back(s2.str());

	s3<<"   Nome: "<<this->nome;
	v.push_back(s3.str());

	s4<<"   Data de Nascimento: "<<this->dataNascimento;
	v.push_back(s4.str());

	return v;
}

string Pessoa::toString()
{
	stringstream ss;
	ss<<"|"<<this->id<<"|"<<this->nome<<"|"<<this->dataNascimento<<"|"<<this->tipo<<"|";
	return ss.str();
}


string Pessoa::toList()
{
    ostringstream ss;
    ss<<"|";
    if (id<10)
        ss<<" ";
	ss<<this->id<<"| "<<this->nome<<" |";

    return ss.str();
}

vector<string> Pessoa::editPessoa()
{
	vector<string> opcoes;
	stringstream ss1,ss2,ss3;
	opcoes.push_back("Escolha o que editar:");
	opcoes.push_back("");
	ss1<<"1 - Editar Nome: "<<this->nome;
	opcoes.push_back(ss1.str());
	ss2<<"2 - Editar Data de Nascimento: "<<this->dataNascimento;
	opcoes.push_back(ss2.str());
/*	ss3<<"3 - Editar Tipo: "<<this->tipo;
	opcoes.push_back(ss3.str());*/

	return opcoes;
}
