///////////////////////////////////////////////////////////
//  Pessoa.h
//  Implementation of the Class Pessoa
//  Created on:      24-Out-2010 20:04:15
///////////////////////////////////////////////////////////

#if !defined(EA_6CFBB159_8536_48f1_9FA4_EEC365A4F94E__INCLUDED_)
#define EA_6CFBB159_8536_48f1_9FA4_EEC365A4F94E__INCLUDED_

#include "funcoes.h"

#include <string>
#include <sstream>
using namespace std;

class Pessoa
{

public:
	Pessoa();
	virtual ~Pessoa();

	Pessoa(string nome, string dataNascimento, string tipo);
	string getName();
	string getDataNascimento();
	virtual string imprime();
	string getTipo();
	void setTipo(string tipo);

private:
	string nome;
	string dataNascimento;
	static int id;
	string tipo;

};
#endif // !defined(EA_6CFBB159_8536_48f1_9FA4_EEC365A4F94E__INCLUDED_)
