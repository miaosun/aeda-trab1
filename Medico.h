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
	Funcionario *m_Funcionario;
	Doente *m_Doente;

	Medico(string nome, string dataNascimento, string especialidade, string horario, double vencimento);
	string imprime();
	string getEspecialidade();
	string getHorario();
	double getVencimento();

private:
	string especialidade;
	string horario;
	double vencimento;

};
#endif // !defined(EA_FC464729_C72D_4115_B003_E0DAD8DDC9B3__INCLUDED_)
