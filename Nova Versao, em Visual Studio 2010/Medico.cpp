///////////////////////////////////////////////////////////
//  Medico.cpp
//  Implementation of the Class Medico
//  Created on:      24-Out-2010 20:04:14
///////////////////////////////////////////////////////////

#include "Medico.h"

/**
 * Construtor por omissao da classe Médico
 */
Medico::Medico(){}

/**
 * Destrutor da classe Médico
 */
Medico::~Medico(){}

/**
 * Construtor da classe Medico com nome, data de nascimento, tipo, especialidade, horario, vencimento
 * @param tipo tipo de Pessoa 
 */
Medico::Medico(string nome, string dataNascimento, string tipo, string especialidade, string horario, double vencimento):Pessoa(nome, dataNascimento, tipo)
{
	this->especialidade = especialidade;
	this->horario = horario;
	this->vencimento = vencimento;
}

/**
 * Funçao que retorna a Especialidade
 */
string Medico::getEspecialidade(){

	return this->especialidade;
}

/**
 * Funçao que modifica a Especialidade
 */
void Medico::setEspecialidade(string especialidade)
{
	this->especialidade = especialidade;
}

/**
 * Funçao que retorna o Horario
 */
string Medico::getHorario(){

	return this->horario;
}

/**
 * Funçao que modifica o Horario
 */
void Medico::setHorario(string horario)
{
	this->horario = horario;
}

/**
 * Funçao que retorna o Vencimento
 */
double Medico::getVencimento(){

	return this->vencimento;
}

/**
 * Funçao que modifica o Vencimento
 */
void Medico::setVencimento(double vencimento)
{
	this->vencimento = vencimento;
}

/**
 * Funçao que imprime
 */
vector<string> Medico::imprime(){

	stringstream s1,s2,s3;
	vector<string> v;
	v=Pessoa::imprime();

	s1<<"   Especialidade: "<<this->especialidade;
	v.push_back(s1.str());

	s2<<"   Horario: "<<this->horario;
	v.push_back(s2.str());

	s3<<"   Vencimento: "<<this->vencimento;
	v.push_back(s3.str());
	return v;
}

/**
 * Funçao 
 */
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

/**
 * Funçao 
 */
string Medico::toString()
{
	stringstream ss;
	ss<<Pessoa::toString()<<this->especialidade<<"|"<<this->horario<<"|"<<this->vencimento<<"|";
	return ss.str();
}


//funcoes abstradas para objecto da superclasse consegue acessar os metodos das classes derivadas
void Medico::setMorada(string morada){}
void Medico::setCargo(string cargo){}
