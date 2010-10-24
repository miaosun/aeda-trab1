///////////////////////////////////////////////////////////
//  Manutencao.h
//  Implementation of the Class Manutencao
//  Created on:      24-Out-2010 20:04:12
//  Original author: Answer
///////////////////////////////////////////////////////////

#if !defined(EA_E50CBA57_B50B_40dd_A248_770E2B968F60__INCLUDED_)
#define EA_E50CBA57_B50B_40dd_A248_770E2B968F60__INCLUDED_

#include "Pessoa.h"
#include "Marcacao.h"

#include <vector>

class Manutencao
{

public:
	virtual ~Manutencao();
	Pessoa *m_Pessoa;
	Marcacao *m_Marcacao;

	Manutencao();
	void addPessoa(Pessoa * p);
	void removePessoa();
	void addMarcacao(Marcacao * mar);
	void removeMarcacao();
	string imprime();
	void load();
	void save();

private:
	vector<Pessoa *> pessoas;
	vector<Marcacao *> marcacoes;

};
#endif // !defined(EA_E50CBA57_B50B_40dd_A248_770E2B968F60__INCLUDED_)
