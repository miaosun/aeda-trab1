///////////////////////////////////////////////////////////
//  Geral.h
//  Implementation of the Class Geral
//  Created on:      24-Out-2010 20:04:11
//  Original author: Answer
///////////////////////////////////////////////////////////

#if !defined(EA_2D9B4F1B_0720_4147_9C31_11800C13C108__INCLUDED_)
#define EA_2D9B4F1B_0720_4147_9C31_11800C13C108__INCLUDED_

#include "Manutencao.h"
#include <iostream>
#include <stdlib.h>

class Geral
{

public:
	Geral();
	virtual ~Geral();
	Manutencao *m_Manutencao;

	void welcome();
	void showMenu(string titulo, vector<string> opcoes);
	void menuPrincipal();
	void menuPessoas();
	void menuMarcacoes();

};
#endif // !defined(EA_2D9B4F1B_0720_4147_9C31_11800C13C108__INCLUDED_)
