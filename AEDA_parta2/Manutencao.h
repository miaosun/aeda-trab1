///////////////////////////////////////////////////////////
//  Manutencao.h
//  Implementation of the Class Manutencao
//  Created on:      24-Out-2010 20:04:12
//  Original author: Answer
///////////////////////////////////////////////////////////

#if !defined(EA_E50CBA57_B50B_40dd_A248_770E2B968F60__INCLUDED_)
#define EA_E50CBA57_B50B_40dd_A248_770E2B968F60__INCLUDED_

//#include "Pessoa.h"
#include "Marcacao.h"
#include "Hospitais.h"

#include <vector>
#include <queue>

class Manutencao
{

public:
	virtual ~Manutencao();
	Pessoa *m_Pessoa;
	Marcacao *m_Marcacao;

	Manutencao();
	void welcome();
	void showMenu(string titulo, vector<string> opcoes);
	void menuPrincipal();
	void menuPessoas();
	void menuMarcacoes();
	void menuEspecialidades();
	string escolheEspecialidade();
	void listaEspecialidades();
	void addEspecialidade();
	void addPessoa();
	void removePessoa(int id);
	void addMarcacao();
	void removeMarcacao(int id);
	void listaMedicos();
	void listaFuncionarios();
	void listaDoentes();
	void listaPessoas();
	void listaMarcacoes();
	void editPessoas(Pessoa *p);
	void editMarcacoes(Marcacao *m);
	void loadPessoas(string filename);
	void savePessoas(string filename);
	void loadMarcacoes(string filename);
	void saveMarcacoes(string filename);
	void saveManutencao();
	void startManutencao();
	void associarFuncionario(Pessoa *p);
	//string imprime();

	void menuHospitais();
	void addHospital();


private:
	vector<Pessoa *> pessoas;
	vector<Marcacao *> marcacoes;
	vector<string> especialidades;
	priority_queue<Hospitais> hospitais;

};
#endif // !defined(EA_E50CBA57_B50B_40dd_A248_770E2B968F60__INCLUDED_)
