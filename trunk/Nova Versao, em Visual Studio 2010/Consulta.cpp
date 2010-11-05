///////////////////////////////////////////////////////////
//  Consulta.cpp
//  Implementation of the Class Consulta
//  Created on:      24-Out-2010 20:04:07
//  Original author: Answer
///////////////////////////////////////////////////////////

#include "Consulta.h"


/**
 * Construtor por omissao da classe Consulta
 */ 
Consulta::Consulta(){}

/**
 * Destrutor da classe Consulta
 */ 
Consulta::~Consulta(){}

/**
 * Construtor da classe Consulta com data , hora e tipo
 * @param data data da consulta
 * @param hora hora da consulta
 * @param tipo tipo
 */ 
Consulta::Consulta(string data, string hora, string tipo):Marcacao(data, hora, tipo)
{

}

/**
 * 
 */ 
string Consulta::toString()
{
	return Marcacao::toString();
}

/**
 * 
 */ 
vector<string> Consulta::imprime()
{
	vector<string> v;

	v=Marcacao::imprime();

	return v;
}

/**
 * 
 */ 
vector<string> Consulta::editMarcacao()
{
	return Marcacao::editMarcacao();
}


//////////////////////////
//
void Consulta::setSala(string sala){}
