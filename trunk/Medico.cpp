///////////////////////////////////////////////////////////
//  Medico.cpp
//  Implementation of the Class Medico
//  Created on:      24-Out-2010 20:04:14
///////////////////////////////////////////////////////////

#include "Medico.h"


Medico::Medico(){}

Medico::~Medico(){}

Medico::Medico(string nome, string dataNascimento, string tipo, string especialidade, string horario, double vencimento):Pessoa(nome, dataNascimento, tipo)
{
	this->especialidade = especialidade;
	this->horario = horario;
	this->vencimento = vencimento;
	this->funcionario = 0;
}

string Medico::getEspecialidade(){

	return this->especialidade;
}

void Medico::setEspecialidade(string especialidade)
{
	this->especialidade = especialidade;
}

string Medico::getHorario(){

	return this->horario;
}

void Medico::setHorario(string horario)
{
	this->horario = horario;
}

double Medico::getVencimento(){

	return this->vencimento;
}

void Medico::setVencimento(double vencimento)
{
	this->vencimento = vencimento;
}

Funcionario *Medico::getFuncionario()
{
	return this->funcionario;
}

void Medico::setFuncionario(Funcionario *funcionario)
{
	this->funcionario = funcionario;
}

vector<string> Medico::imprime(){

	stringstream ss1,ss2,ss3,ss4;
	vector<string> v;
	v=Pessoa::imprime();

	ss1<<"   Especialidade: "<<this->especialidade;
	v.push_back(ss1.str());

	ss2<<"   Horario: "<<this->horario;
	v.push_back(ss2.str());

	ss3<<"   Vencimento: "<<this->vencimento;
	v.push_back(ss3.str());

	ss4<<"  Funcionario Associado(ID, nome): "<<funcionario->getId()<<", "<<funcionario->getName();
	return v;
}

vector<string> Medico::editPessoa()
{
	vector<string> opcoes;
	opcoes = Pessoa::editPessoa();
	stringstream ss1,ss2,ss3;

	ss1<<"3 - Editar Especialidade: "<<this->especialidade;
	opcoes.push_back(ss1.str());
	ss2<<"4 - Editar Horario: "<<this->horario;
	opcoes.push_back(ss2.str());
	ss3<<"5 - Editar Vencimento: "<<this->vencimento;
	opcoes.push_back(ss3.str());

	return opcoes;
}

string Medico::toString()
{
	stringstream ss;
	ss<<Pessoa::toString()<<this->especialidade<<"|"<<this->horario<<"|"<<this->vencimento<<"|";
	return ss.str();
}


//funcoes abstradas para objecto da superclasse consegue acessar os metodos das classes derivadas
void Medico::setMorada(string morada){}
void Medico::setCargo(string cargo){}
string Medico::getCargo(){return "";}
