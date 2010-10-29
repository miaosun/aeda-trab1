///////////////////////////////////////////////////////////
//  Doente.h
//  Implementation of the Class Doente
//  Created on:      24-Out-2010 20:04:09
//  Original author: Answer
///////////////////////////////////////////////////////////

#if !defined(EA_6B04B8B3_574E_437d_9E32_00DB174900BC__INCLUDED_)
#define EA_6B04B8B3_574E_437d_9E32_00DB174900BC__INCLUDED_

#include "Pessoa.h"

class Doente : public Pessoa
{

public:
	Doente();
	virtual ~Doente();

	Doente(string nome, string dataNascimento, string tipo, string morada);
	vector<string> imprime();
	string getMorada();

private:
	string morada;

};
#endif // !defined(EA_6B04B8B3_574E_437d_9E32_00DB174900BC__INCLUDED_)
