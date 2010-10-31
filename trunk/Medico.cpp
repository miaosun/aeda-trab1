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
/*
	stringstream ss;
	ss<<"Medico:\n";
	ss<<"\\t"<<Pessoa::imprime()<<"Especialidade: "<<this->especialidade<<"\nHorario: "<<this->horario<<"\nVencimento: "<<vencimento<<endl;
	return ss.str();*/

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

string Medico::toList()
{
	stringstream s;

	s<<Pessoa::toList()<<" | "<<this->especialidade<<" | "<<this->horario<<" | "<<this->vencimento;

	return s.str();
}
