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

