/*
 * Excepcoes.h
 *
 *  Created on: 27 de Out de 2010
 *      Author: Answer
 */

#ifndef EXCEPCOES_H_
#define EXCEPCOES_H_

#include <iostream>

class tipoPessoaInvalida
{
public:
	string devia_ser, foi;
	tipoPessoaInvalida(string devia_ser, string foi)
	{
		this->devia_ser=devia_ser;
		this->foi=foi;
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

class NotFound {};

#endif /* EXCEPCOES_H_ */
