///////////////////////////////////////////////////////////
//  Marcacao.h
//  Implementation of the Class Marcacao
//  Created on:      24-Out-2010 20:04:13
//  Original author: Answer
///////////////////////////////////////////////////////////

#if !defined(EA_6D34D39A_7937_43d1_9953_2455A3DEDC2B__INCLUDED_)
#define EA_6D34D39A_7937_43d1_9953_2455A3DEDC2B__INCLUDED_

#include "Pessoa.h"
#include "Doente.h"
#include "Medico.h"

#include <string>
#include <vector>
using namespace std;

class Marcacao
{

public:
	Marcacao();
	virtual ~Marcacao();

	Marcacao(string data, string hora, string tipo, Pessoa * medico, Pessoa * doente);
	string getData();
	void setData(string data);
	string getHora();
	void setHora(string hora);
	string getTipo();
	void setTipo(string tipo);
	int getId() const;
	string toList();
	Pessoa * getMedico();
	void setMedico(Pessoa * medico);
	Pessoa * getDoente();
	void setDoente(Pessoa * doente);

	virtual string toString();
	virtual vector<string> imprime();
	virtual vector<string> editMarcacao();

	///////////////////////////////////////
	//
	virtual void setSala(string sala) = 0;


private:
	string data;
	string hora;
	int id;
	string tipo;
	static int count;
	Pessoa * medico;
	Pessoa * doente;

};
#endif // !defined(EA_6D34D39A_7937_43d1_9953_2455A3DEDC2B__INCLUDED_)
