///////////////////////////////////////////////////////////
//  Doente.cpp
//  Implementation of the Class Doente
//  Created on:      24-Out-2010 20:04:09
//  Original author: Answer
///////////////////////////////////////////////////////////

#include "Doente.h"

/**
 * Construtor por omissao da classe Doente
 */
Doente::Doente(){}

/**
 * Destrutor da classe Doente
 */
Doente::~Doente(){}


/**
 * Construtor da classe Doente com nome, data de nascimento, tipo, morada
 * @param tipo tipo de Pessoa 
 */
Doente::Doente(string nome, string dataNascimento, string tipo, string morada):Pessoa(nome, dataNascimento, tipo)
{
	this->morada = morada;
}


/**
 * Funçao que retorna a Morada do Doente
 */
string Doente::getMorada(){

	return this->morada;
}


/**
 * Funçao que modifica a morada do Doente
 */
void Doente::setMorada(string morada)
{
	this->morada = morada;
}


/**
 * Funçao que imprime 
 */
vector<string> Doente::imprime(){

	stringstream s;
	vector<string> v;
	v=Pessoa::imprime();

	s<<"   Morada: "<<this->morada;
	v.push_back(s.str());

	return v;
}

/**
 * Função
 */
vector<string> Doente::editPessoa()
{
	vector<string> opcoes;
	stringstream ss;
	opcoes = Pessoa::editPessoa();

	ss<<"4 - Editar Morada: "<<this->morada;
	opcoes.push_back(ss.str());

	return opcoes;
}


/**
 * 
 */
string Doente::toString()
{
	stringstream ss;
	ss<<Pessoa::toString()<<this->morada<<"|";
	return ss.str();
}

/**
 * 
 */
void Doente::setEspecialidade(string especialidade){}
void Doente::setVencimento(double venc){}
void Doente::setHorario(string horario){}
void Doente::setCargo(string cargo){}
