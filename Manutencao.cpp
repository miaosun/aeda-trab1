///////////////////////////////////////////////////////////
//  Manutencao.cpp
//  Implementation of the Class Manutencao
//  Created on:      24-Out-2010 20:04:12
//  Original author: Answer
///////////////////////////////////////////////////////////

#include "Manutencao.h"


Manutencao::~Manutencao(){

}





Manutencao::Manutencao(){

}


void Manutencao::addPessoa(Pessoa * p){

	this->pessoas.push_back(p);
}


void Manutencao::removePessoa(string nome){

	vector<Pessoa *>::iterator it;
	for(it=pessoas.begin(); it!=pessoas.end(); it++)
	{
		if((*it)->getName() == nome)
			pessoas.erase(it);
	}
}


void Manutencao::addMarcacao(Marcacao * mar){

	this->marcacoes.push_back(mar);
}


void Manutencao::removeMarcacao(){

}


string Manutencao::imprime(){

	return  NULL;
}


void Manutencao::load(){

}


void Manutencao::save(){

}
