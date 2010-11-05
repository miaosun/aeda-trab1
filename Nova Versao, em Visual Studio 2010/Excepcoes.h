/*
 * Excepcoes.h
 *
 *  Created on: 27 de Out de 2010
 *      Author: Answer
 */

#ifndef EXCEPCOES_H_
#define EXCEPCOES_H_

#include <iostream>

class notIntInput
{
public:
	int op;
	notIntInput(int op)
	{
		this->op=op;
	}
};

class tipoInvalido
{
public:
	string tipo;
	tipoInvalido(string tipo)
	{
		this->tipo=tipo;
	}
};

class DataInvalida 
{
public:
	int dia, mes, ano;
	DataInvalida(int dia, int mes, int ano)
	{
		this->dia = dia;
		this->mes = mes;
		this->ano = ano;
	}
};

class HoraInvalida
{
public:
	int hora_ini, hora_fim;
	HoraInvalida(int hora_ini, int hora_fim){this->hora_ini=hora_ini;this->hora_fim=hora_fim;}
};
#endif /* EXCEPCOES_H_ */
