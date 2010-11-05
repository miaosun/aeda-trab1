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
	string getCargo();
	void setCargo(string cargo);
	double getVencimento();
	void setVencimento(double vencimento);
	vector<string> imprime();
	vector<string> editPessoa();
	string toString();

	//funcoes abstradas para objecto da superclasse consegue acessar os metodos das classes derivadas
	void setEspecialidade(string especialidade);
	void setHorario(string hora);
	void setMorada(string morada);
	string getEspecialidade();
	string getHorario();


private:
	string cargo;
	double vencimento;

};
#endif // !defined(EA_340DED97_7376_438f_A48A_945CB7751935__INCLUDED_)
