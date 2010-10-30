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

	Exame(string data, string hora, string sala, string tipo);
	string getSala();
	void setSala();
	vector<string> imprime();

private:
	string sala;

};
#endif // !defined(EA_C770FA25_5477_45dd_BD95_171CA4C42559__INCLUDED_)
