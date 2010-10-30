///////////////////////////////////////////////////////////
//  Consulta.h
//  Implementation of the Class Consulta
//  Created on:      24-Out-2010 20:04:07
//  Original author: Answer
///////////////////////////////////////////////////////////

#if !defined(EA_58523BA4_83E1_4418_9232_D55F12BD24FC__INCLUDED_)
#define EA_58523BA4_83E1_4418_9232_D55F12BD24FC__INCLUDED_

#include "Marcacao.h"

class Consulta : public Marcacao
{

public:
	Consulta();
	virtual ~Consulta();

	Consulta(string data, string hora, string tipo);
	string imprime();

};
#endif // !defined(EA_58523BA4_83E1_4418_9232_D55F12BD24FC__INCLUDED_)
