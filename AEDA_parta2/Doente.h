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
	string getMorada();
	void setMorada(string morada);
	vector<string> imprime();
	vector<string> editPessoa();
	string toString();

	//funcoes abstradas para objecto da superclasse consegue acessar os metodos das classes derivadas
	void setEspecialidade(string especialidade);
	void setHorario(string hora);
	void setVencimento(double venc);
	void setCargo(string cargo);
	string getCargo();
	double getVencimento();
	string getEspecialidade();
	string getHorario();
	void showMedicos();
	void addMedico(Pessoa * medico);
	void addMedico(Pessoa * medico, string especialidade);
	vector<Pessoa *> * getMedicos(string especialidade);
	Pessoa * getFuncionario(){Pessoa * p; return p;};
	void setFuncionario(Pessoa * func){};
	void findMedicos(string especialidade);

	
	void addEspec(string d_esp);

private:
	string morada;
	vector<Pessoa *> medicos;
	vector<string> d_espec;

};
#endif // !defined(EA_6B04B8B3_574E_437d_9E32_00DB174900BC__INCLUDED_)
