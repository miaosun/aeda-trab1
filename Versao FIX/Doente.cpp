///////////////////////////////////////////////////////////
//  Doente.cpp
//  Implementation of the Class Doente
//  Created on:      24-Out-2010 20:04:09
//  Original author: Answer
///////////////////////////////////////////////////////////

#include "Doente.h"
#include "Excepcoes.h"


Doente::Doente(){}

Doente::~Doente(){}


Doente::Doente(string nome, string dataNascimento, string tipo, string morada):Pessoa(nome, dataNascimento, tipo)
{
	this->morada = morada;
}

void Doente::addMedico(Pessoa * medico)
{
	if(medico->getTipo()!="Medico")
		throw tipoPessoaInvalida("Medico", medico->getTipo());
	else
	{
		for(unsigned int i=0; i<medicos.size(); i++)
		{
			if(medico==medicos.at(i))
			{
				cout<<"Medico ja associado!"<<endl;
				system("pause");
				return;
			}
		}
		medicos.push_back(medico);
	}
}

vector<Pessoa *> * Doente::getMedicos()
{
	return &this->medicos;
}

string Doente::getMorada(){

	return this->morada;
}

void Doente::setMorada(string morada)
{
	this->morada = morada;
}

vector<string> Doente::imprime(){

	stringstream ss;
	vector<string> v;
	v=Pessoa::imprime();

	ss<<"   Morada: "<<this->morada;
	v.push_back(ss.str());

	return v;
}

vector<string> Doente::editPessoa()
{
	vector<string> opcoes;
	stringstream ss, ss1, ss2;
	opcoes = Pessoa::editPessoa();

	ss<<"3 - Editar Morada: "<<this->morada;
	opcoes.push_back(ss.str());

	ss1<<"4 - Adicionar medico";
	opcoes.push_back(ss1.str());

	ss2<<"5 - Ver medicos";
	opcoes.push_back(ss2.str());

	return opcoes;
}

void Doente::showMedicos()
{
	system("cls");
	cout<<"Medicos que acompanham o doente:\n";
	if(medicos.empty())
		cout<<"\n\tNao tem medico associado!\n";
	else
	{
		cout<<"\n\tID   Nome";
		for(unsigned int i=0; i<medicos.size(); i++)
		{
			cout<<"\n\t"<<medicos[i]->getId()<<", "<<medicos[i]->getName();
		}
	}
	cout<<endl;
}

string Doente::toString()
{
	stringstream ss;
	ss<<Pessoa::toString()<<this->morada<<"|";
	return ss.str();
}

//funcoes abstradas para objecto da superclasse consegue acessar os metodos das classes derivadas
void Doente::setEspecialidade(string especialidade){}
void Doente::setVencimento(double venc){}
void Doente::setHorario(string horario){}
void Doente::setCargo(string cargo){}
string Doente::getCargo(){return "";}
double Doente::getVencimento(){return NULL;}
string Doente::getEspecialidade(){return "";};
string Doente::getHorario(){return "";};