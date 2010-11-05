/*
 * funcoes.h
 *
 *  Created on: 25 de Out de 2010
 *      Author: Answer
 */
#ifndef FUNCOES_H_
#define FUNCOES_H_

#include "Excepcoes.h"

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

vector<string> split(char delim, string s)
{
	size_t cutAt;
	vector<string> result;
	while( (cutAt = s.find_first_of(delim)) != s.npos )
	{
		if( cutAt > 0 )
		{
			result.push_back( s.substr( 0, cutAt ) );
		}
		s = s.substr( ++cutAt );
	}
	return result;
}

bool isDouble(const string& s)
{
  istringstream i(s);
  double temp;
  return ( (i >> temp) ? true : false );
}

bool isDigit(const string& s)
{
	istringstream i(s);
	int temp;
	return ( (i >> temp) ? true : false );
}

int intinput()
{
	string s;
	int i=0;
	getline(cin, s);
	while(!isDigit(s))
	{
		cout<<"A opcao nao e valida, tenta novamente: ";
		getline(cin, s);
	};

	i = atoi(s.c_str());
	return i;
}


double inserirVencimento()
{
	string s;
	double d=0.0;
	
	do
	{
		cout<<"Vencimento(tem que ser digital): ";
		getline(cin,s);
	}while(!isDouble(s));

	d = strtod(s.c_str(),NULL);

	return d;
}

void inserirTipo()
{
	string tipo;
	getline(cin, tipo);
	if(tipo!="Medico"&&tipo!="Doente"&&tipo!="Funcionario")
		throw tipoInvalido(tipo);
}

string inserirData(string data)
{
	stringstream ss, saida;
	int dia, mes, ano;
	getline(cin, data);
	ss<<data;
	ss>>dia;
	ss>>mes;
	ss>>ano;
	if(ano>2010||ano<1920)
		throw DataInvalida(dia, mes, ano);
	if(mes>12||mes<1)
		throw DataInvalida(dia, mes, ano);
	if(mes==4||mes==6||mes==9||mes==11)
	{
		if(dia>30||dia<1)
			throw DataInvalida(dia, mes, ano);
	}
	else if(mes==2)
	{
		if(dia>28||dia<1)
			throw DataInvalida(dia, mes, ano);
	}
	else if(dia>31||dia<1)
		throw DataInvalida(dia, mes, ano);
	
	saida<<dia<<"/"<<mes<<"/"<<ano;
	data = saida.str();
	ss.str("");
	saida.str("");
	return data;

}

string inserirHorario(string hora)
{
	stringstream ss, saida;
	int hora_ini, hora_fim;
	cout<<"Horario(inicio fim (inteiro)) (ex: 9 19): ";
	getline(cin, hora);
	ss<<hora;
	ss>>hora_ini;
	ss>>hora_fim;

	if(hora_ini>=hora_fim||(hora_ini<9||hora_ini>21)||(hora_fim<9||hora_fim>21))
		throw HoraInvalida(hora_ini, hora_fim);

	saida<<hora_ini<<"h-"<<hora_fim<<"h";
	hora=saida.str();
	ss.str("");
	saida.str("");
	return hora;
}

#endif /* FUNCOES_H_ */
