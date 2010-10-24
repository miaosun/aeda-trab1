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


string Funcionario::imprime(){

	stringstream ss;
	ss<<"Funcionario:\n";
	ss<<"\\t"<<Pessoa::imprime()<<"\nCargo: "<<cargo<<"\nVencimento: "<<vencimento<<endl;
	return ss.str();
}


string Funcionario::getCargo(){

	return this->cargo;
}


double Funcionario::getVencimento(){

	return this->vencimento;
}
