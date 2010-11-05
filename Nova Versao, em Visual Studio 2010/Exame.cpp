///////////////////////////////////////////////////////////
//  Exame.cpp
//  Implementation of the Class Exame
//  Created on:      24-Out-2010 20:04:10
//  Original author: Answer
///////////////////////////////////////////////////////////

#include "Exame.h"

/**
 * Construtor por omissao da classe Exame
 */ 
Exame::Exame(){}

/**
 * Destrutor da classe Exame
 */
Exame::~Exame(){}

/**
 * Construtor da classe Exame com data, tipo, sala
 * @param 
 */
Exame::Exame(string data, string hora, string tipo, string sala):Marcacao(data, hora, tipo)
{
	this->sala = sala;
}

/**
 * Construtor da classe Exame com data, tipo, sala
 */
string Exame::getSala(){

	return this->sala;
}

void Exame::setSala(string sala){

	this->sala = sala;
}

string Exame::toString()
{
	stringstream ss;
	ss<<Marcacao::toString()<<this->sala<<"|";
	return ss.str();
}

vector<string> Exame::imprime(){

	vector<string> v;
	stringstream s;

	v=Marcacao::imprime();

	s<<"   Sala: "<<this->sala;
	v.push_back(s.str());

	return v;
}

vector<string> Exame::editMarcacao()
{
	vector<string> opcoes;
	stringstream ss;
	opcoes = Marcacao::editMarcacao();

	ss<<"4 - Editar Sala: "<<this->sala;
	opcoes.push_back(ss.str());

	return opcoes;
}

