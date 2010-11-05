///////////////////////////////////////////////////////////
//  Medico.h
//  Implementation of the Class Medico
//  Created on:      24-Out-2010 20:04:14
///////////////////////////////////////////////////////////

#if !defined(EA_FC464729_C72D_4115_B003_E0DAD8DDC9B3__INCLUDED_)
#define EA_FC464729_C72D_4115_B003_E0DAD8DDC9B3__INCLUDED_

#include "Pessoa.h"
#include "Funcionario.h"
#include "Doente.h"

class Medico : public Pessoa
{

public:
	Medico();
	virtual ~Medico();
	Funcionario *f_Funcionario;
	Doente *m_Doente;

	Medico(string nome, string dataNascimento, string tipo, string especialidade, string horario, double vencimento);
	string getEspecialidade();
	void setEspecialidade(string especialidade);
	string getHorario();
	void setHorario(string horario);
	double getVencimento();
	void setVencimento(double vencimento);
	Funcionario *getFuncionario();
	void setFuncionario(Funcionario *funcionario);
	vector<string> imprime();
	vector<string> editPessoa();
	string toString();

	//funcoes abstradas para objecto da superclasse consegue acessar os metodos das classes derivadas
	void setMorada(string morada);
	void setCargo(string cargo);
	string getCargo();

private:
	string especialidade;
	string horario;
	double vencimento;
	Funcionario *funcionario;

};
#endif // !defined(EA_FC464729_C72D_4115_B003_E0DAD8DDC9B3__INCLUDED_)
