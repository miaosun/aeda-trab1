
#include "Pessoa.h"

class Hospitais
{
	string nome;
	string morada;
	string tipo;
	int distancia;
	vector<Pessoa *> pes;
	vector<string> esp;

public:
	Hospitais(string nome, string morada, int distancia, string tipo);
	string getName();
	void setName(string nome);
	string getMorada();
	void setMorada(string morada);
	int getDistancia();
	void setDistancia(int distancia);
	string getTipo();
	bool operator < (const Hospitais &hps) const;
	friend ostream & operator << (ostream& os, Hospitais hps);
};