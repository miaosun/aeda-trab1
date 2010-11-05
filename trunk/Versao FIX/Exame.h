///////////////////////////////////////////////////////////
//  Exame.h
//  Implementation of the Class Exame
//  Created on:      24-Out-2010 20:04:10
//  Original author: Answer
///////////////////////////////////////////////////////////

#if !defined(EA_C770FA25_5477_45dd_BD95_171CA4C42559__INCLUDED_)
#define EA_C770FA25_5477_45dd_BD95_171CA4C42559__INCLUDED_

#include "Marcacao.h"

class Exame : public Marcacao
{

public:
	Exame();
	virtual ~Exame();

	Exame(string data, string hora, string tipo, Pessoa * medico, Pessoa * doente, string sala);
	string getSala();
	void setSala(string sala);
	string toString();
	vector<string> imprime();
	vector<string> editMarcacao();

private:
	string sala;

};
#endif // !defined(EA_C770FA25_5477_45dd_BD95_171CA4C42559__INCLUDED_)
