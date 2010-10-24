///////////////////////////////////////////////////////////
//  Marcacao.h
//  Implementation of the Class Marcacao
//  Created on:      24-Out-2010 20:04:13
//  Original author: Answer
///////////////////////////////////////////////////////////

#if !defined(EA_6D34D39A_7937_43d1_9953_2455A3DEDC2B__INCLUDED_)
#define EA_6D34D39A_7937_43d1_9953_2455A3DEDC2B__INCLUDED_

#include "Doente.h"
#include "Medico.h"

class Marcacao
{

public:
	Marcacao();
	virtual ~Marcacao();
	Doente *m_Doente;
	Medico *m_Medico;

	Marcacao(string data, string hora);
	virtual string imprime();
	string getData();
	void setData();
	string getHora();
	void setHora();

private:
	string data;
	string hora;

};
#endif // !defined(EA_6D34D39A_7937_43d1_9953_2455A3DEDC2B__INCLUDED_)
