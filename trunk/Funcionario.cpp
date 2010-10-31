///////////////////////////////////////////////////////////
//  Funcionario.cpp
//  Implementation of the Class Funcionario
//  Created on:      24-Out-2010 20:04:11
//  Original author: Answer
///////////////////////////////////////////////////////////

#include "Funcionario.h"


Funcionario::Funcionario(){

}



Funcionario::~Funcionario(){

}





Funcionario::Funcionario(string nome, string dataNascimento, string tipo, string cargo, double vencimento):Pessoa(nome, dataNascimento, tipo)
{
	this->cargo = cargo;
	this->vencimento = vencimento;
}


vector<string> Funcionario::imprime(){

	stringstream s1,s2;
	vector<string> v;
	v=Pessoa::imprime();

	s1<<"   Cargo: "<<this->cargo;
	v.push_back(s1.str());

	s2<<"   Vencimento: "<<this->vencimento;
	v.push_back(s2.str());
	return v;
}


string Funcionario::getCargo(){

	return this->cargo;
}


double Funcionario::getVencimento(){

	return this->vencimento;
}

vector<string> Funcionario::editPessoa()
{
	vector<string> opcoes;
	opcoes = Pessoa::editPessoa();
	stringstream ss1,ss2;

	ss1<<"4 - Editar Cargo: "<<this->cargo;
	opcoes.push_back(ss1.str());
	ss2<<"5 - Editar Vencimento: "<<this->vencimento;
	opcoes.push_back(ss2.str());

	return opcoes;
}

void Funcionario::setCargo(string cargo)
{
	this->cargo = cargo;
}

void Funcionario::setVencimento(double vencimento)
{
	this->vencimento = vencimento;
}

//funcoes abstradas para objecto da superclasse consegue acessar os metodos das classes derivadas
void Funcionario::setEspecialidade(string especialidade){}
void Funcionario::setHorario(string hora){}
void Funcionario::setMorada(string morada){}
