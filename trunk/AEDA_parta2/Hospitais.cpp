
#include "Hospitais.h"

Hospitais::Hospitais(string nome, string morada, int distancia, string tipo)
{
	this->nome = nome;
	this->morada = morada;
	this->distancia = distancia;
	this->tipo = tipo;
}

string Hospitais::getName()
{
	return this->nome;
}

void Hospitais::setName(string nome)
{
	this->nome = nome;
}

string Hospitais::getMorada()
{
	return this->morada;
}

void Hospitais::setMorada(string morada)
{
	this->morada = morada;
}

int Hospitais::getDistancia()
{
	return this->distancia;
}

void Hospitais::setDistancia(int distancia)
{
	this->distancia = distancia;
}

string Hospitais::getTipo()
{
	return this->tipo;
}

bool Hospitais::operator < (const Hospitais &hps) const
{
	return distancia > hps.distancia;
}

ostream & operator << (ostream & os, Hospitais hps)
{
	os<<hps.tipo<<endl;
	os<<"\tNome do "<<hps.tipo<<": "<<hps.getName()<<endl;
	os<<"\tMorada do "<<hps.tipo<<": "<<hps.getMorada()<<endl;
	os<<"\tDistancia: "<<hps.getDistancia()<<endl;
	os<<"\tEspecialidades disponiveis :";
	for(unsigned int i=0; i<hps.esp_hps.size(); i++)
	{
		os<<"\t\t"<<hps.esp_hps[i]<<endl;
	}
	return os;
}

string Hospitais::toString()
{
	stringstream ss;
	ss<<"|"<<this->nome<<"|"<<this->morada<<"|"<<this->distancia<<"|"<<tipo<<"|";
	return ss.str();
}