
#include "Pessoa.h"

class Hospitais
{
	string nome;
	string morada;
	string tipo;
	vector<Pessoa *> pes;
	vector<string> esp;

public:
	Hospitais(string nome, string morada, string tipo);
	string getName();
	void setName(string nome);
	string getMorada();
	void setMorada(string morada);
	string getTipo();
};