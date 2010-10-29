/*
 * funcoes.h
 *
 *  Created on: 25 de Out de 2010
 *      Author: Answer
 */
#ifndef FUNCOES_H_
#define FUNCOES_H_

#include "Excecoes.h"

#include <vector>
#include <string>
#include <sstream>
#include <iostream>

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
		if( s.length() > 0 )
		result.push_back( s );
	}
	return result;
}
/*
int intinput()
{
    stringstream entrada;
    string sintinput;
    int saida;
    getline(cin, sintinput);
    entrada<<sintinput;
    entrada>>saida;
    if(entrada.eofbit||entrada.failbit)
    {
        //throw IntInput();
        return -1;
    }
    else
        return saida;

	cin>>op;
	if(!isdigit(op))
		throw notIntInput(op);
	else
		return op;

}*/

int intinput()
{
    stringstream entrada;
    string sintinput;
    int saida=0;
    getline(cin, sintinput);
    entrada<<sintinput;
    entrada>>saida;
    while(entrada.fail())
    {
        cout<<"O que era pedido era um numero! Tente novamente: ";
        getline(cin, sintinput);
		entrada.str(sintinput);
		entrada.clear();
		entrada>>saida;
    }
    return saida;
}


#endif /* FUNCOES_H_ */
