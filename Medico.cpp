///////////////////////////////////////////////////////////
//  Medico.cpp
//  Implementation of the Class Medico
//  Created on:      24-Out-2010 20:04:14
///////////////////////////////////////////////////////////

#include "Medico.h"


Medico::Medico(){

}



Medico::~Medico(){

}





Medico::Medico(string nome, string dataNascimento, string tipo, string especialidade, string horario, double vencimento):Pessoa(nome, dataNascimento, tipo)
{
	this->especialidade = especialidade;
	this->horario = horario;
	this->vencimento = vencimento;
}


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

void Medico::setMorada(string morada){}
void Medico::setCargo(string cargo){}

vector<string> Medico::editPessoa()
{
	vector<string> opcoes;
	opcoes = Pessoa::editPessoa();
	stringstream ss1,ss2,ss3;

	ss1<<"4 - Editar Especialidade: "<<this->especialidade;
	opcoes.push_back(ss1.str());
	ss2<<"5 - Editar Horario: "<<this->horario;
	opcoes.push_back(ss2.str());
	ss3<<"6 - Editar Vencimento: "<<this->vencimento;
	opcoes.push_back(ss3.str());

	return opcoes;
}
