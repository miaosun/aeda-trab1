/*
 * Excecoes.h
 *
 *  Created on: 27 de Out de 2010
 *      Author: Answer
 */

#ifndef EXCECOES_H_
#define EXCECOES_H_

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


#endif /* EXCECOES_H_ */
