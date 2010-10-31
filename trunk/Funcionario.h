///////////////////////////////////////////////////////////
//  Funcionario.h
//  Implementation of the Class Funcionario
//  Created on:      24-Out-2010 20:04:11
//  Original author: Answer
///////////////////////////////////////////////////////////

#if !defined(EA_340DED97_7376_438f_A48A_945CB7751935__INCLUDED_)
#define EA_340DED97_7376_438f_A48A_945CB7751935__INCLUDED_

#include "Pessoa.h"

class Funcionario : public Pessoa
{

public:
	Funcionario();
	virtual ~Funcionario();

	Funcionario(string nome, string dataNascimento, string tipo, string cargo, double vencimento);
	vector<string> imprime();
	string getCargo();
	double getVencimento();
	vector<string> editPessoa();

private:
	string cargo;
	double vencimento;

};
#endif // !defined(EA_340DED97_7376_438f_A48A_945CB7751935__INCLUDED_)
