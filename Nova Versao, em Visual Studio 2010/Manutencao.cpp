///////////////////////////////////////////////////////////
//  Manutencao.cpp
//  Implementation of the Class Manutencao
//  Created on:      24-Out-2010 20:04:12
//  Original author: Answer
///////////////////////////////////////////////////////////

#include "Manutencao.h"
#include "Excepcoes.h"
#include "funcoes.h"
#include <iostream>
#include <stdlib.h>
#include "Consulta.h"
#include "Exame.h"

#include <fstream>
using namespace std;


Manutencao::Manutencao(){}

Manutencao::~Manutencao(){}

void Manutencao::welcome()
{
	stringstream o;
	for(unsigned int i=0; i<79; i++)
		o<<"*";
	o<<endl;
	for (unsigned int i=0; i<3; i++)
	{
		o<<"*";
		for(unsigned int j=0; j<77; j++)
			o<<" ";
		o<<"*"<<endl;
	}
	o<<"*                    *****   *      *   *****   *   *****                     *\n";
	o<<"*                   *     *  *         *     *     *     *                    *\n";
	o<<"*                   *        *      *  *     *  *  *                          *\n";
	o<<"*                   *        *      *  *     *  *  *                          *\n";
	o<<"*                   *     *  *   *  *  *     *  *  *     *                    *\n";
	o<<"*                    *****    * *   *  *     *  *   *****                     *\n";
	for (unsigned int i=0; i<3; i++)
	{
		o<<"*";
		for(unsigned int j=0; j<77; j++)
			o<<" ";
		o<<"*"<<endl;
	}
	o<<"*       **** ****     ***     *****     ***     *****   *******   *****       *\n";
	o<<"*      *    *    *   *   *   *     *   *   *   *     *  *        *     *      *\n";
	o<<"*      *    *    *  *     *  *     *  *     *  *        *        *     *      *\n";
	o<<"*      *    *    *  *     *  *     *  *     *  * *****  *******  ******       *\n";
	o<<"*      *    *    *  * *** *  *     *  * *** *  * *   *  *        *   *        *\n";
	o<<"*      *    *    *  *     *  *     *  *     *   *****   *******  *     *      *\n";
	for (unsigned int i=0; i<3; i++)
	{
		o<<"*";
		for(unsigned int j=0; j<77; j++)
			o<<" ";
		o<<"*"<<endl;
	}
	for(unsigned int i=0; i<79; i++)
		o<<"*";
	cout<<o.str()<<endl<<endl;
	system("pause");
}

void Manutencao::showMenu(string titulo, vector<string> opcoes)
{
    //clear();
    unsigned int aux;
    for(unsigned int i=0; i<79; i++)
        cout<<"*";
    cout<<endl<<"*****";
    for(unsigned int i=0; i<69; i++)
        cout<<" ";
    cout<<"*****"<<endl<<"*****";
    for(unsigned int i=0; i<26; i++)
        cout<<" ";
    cout<<"-Clinic Manager- ";
    for(unsigned int i=0; i<26; i++)
        cout<<" ";
    cout<<"*****"<<endl<<"*****";
    for(unsigned int i=0; i<69; i++)
        cout<<" ";
    cout<<"*****"<<endl<<"*****";
    aux=69-titulo.length();
    if(aux%2==0)
    {
        for(unsigned int i=0; i<aux/2; i++)
            cout<<" ";
        cout<<titulo;
        for(unsigned int i=0; i<aux/2; i++)
            cout<<" ";
        cout<<"*****"<<endl;
    }
    else
    {
        aux=68-titulo.length();
        for(unsigned int i=0; i<aux/2; i++)
            cout<<" ";
        cout<<titulo;
        for(unsigned int i=0; i<aux/2+1; i++)
            cout<<" ";
        cout<<"*****"<<endl;
    }
    cout<<"*****";
    for(unsigned int i=0; i<69; i++)
        cout<<" ";
    cout<<"*****"<<endl;
    for(unsigned int i=0; i<79; i++)
        cout<<"*";
    cout<<endl<<"*";
    for(unsigned int i=0; i<77; i++)
        cout<<" ";
    cout<<"*"<<endl;
    for(unsigned int i=1; i<=opcoes.size(); i++)
    {
        cout<<"*   "<<opcoes.at(i-1);
        aux=74-opcoes.at(i-1).length();
        for (unsigned int j=0; j<aux; j++)
            cout<<" ";
        cout<<"*"<<endl;
    }
    aux=14-opcoes.size();
    for (unsigned int i=0; i<aux; i++)
    {
        cout<<"*";
        for(unsigned int j=0; j<77; j++)
            cout<<" ";
        cout<<"*"<<endl;
    }
    for(unsigned int i=0; i<79; i++)
        cout<<"*";
    cout<<endl<<endl;
}

void Manutencao::menuPrincipal()
{
    int op;
    vector<string> opcoes;
    opcoes.push_back("Escolha uma das seguintes opcoes:");
    opcoes.push_back("");

    opcoes.push_back("1 - Gestao de Pessoas");
    opcoes.push_back("2 - Gestao de Marcacoes");
    opcoes.push_back("");
    opcoes.push_back("0 - Gravar e sair");

    showMenu("Menu Principal", opcoes);
    cout<<"    Opcao: ";
    op=intinput();

    switch(op)
    {
    case 1:
        menuPessoas(); //vai para menu pessoas
        menuPrincipal(); //volta ao menu principal
        break;
    case 2:
        menuMarcacoes(); //vai para menu marcacoes
        menuPrincipal(); //volta ao menu principal
        break;
    case 0:
		saveManutencao();
		system("pause");
        break;
    default:
        cout<<"Opcao invalida! Insira uma das opcoes disponiveis"<<endl;
        menuPrincipal();
    }
}

void Manutencao::menuPessoas()
{
	int op;
	Pessoa *p;
	vector<string> opcoes;
	string filename;
	opcoes.push_back("Escolha uma das seguintes opcoes:");
	opcoes.push_back("");
	opcoes.push_back("1 - Nova Pessoa");//opcao 1
	if(pessoas.size()>0)
	{
		opcoes.push_back("2 - Ver detalhes de uma Pessoa");//opcao 2
		opcoes.push_back("3 - Editar uma Pessoa");//opcao 3
		opcoes.push_back("4 - Apagar uma Pessoa");//opcao 4
		opcoes.push_back("5 - Importar Pessoas dum ficheiro");//opcao 5
		opcoes.push_back("6 - Exportar Pessoas para ficheiro");//opcao 6
	}
	else
		opcoes.push_back("2 - Importar Pessoas do ficheiro");
	opcoes.push_back("");
	opcoes.push_back("0 - Voltar atras");//opcao 7

	showMenu("Gestao de Pessoas", opcoes);
	cout<<"    Opcao: ";
	op=intinput();
	system("cls");


	if(pessoas.size()>0)
	{
		switch(op)
		{
		case 1:
			cout<<"   --Adicionar Pessoa--"<<endl<<endl;
			addPessoa();
			showMenu("Nova Pessoa", pessoas.back()->imprime());
			system("pause");
			menuPessoas();
			break;
		case 2://ver detalhes Pessoas
			listaPessoas();
			cout<<endl<<"Introduza o ID da Pessoa que pretende ver os detalhes: ";
			int id;
			id=intinput();

			//falta implementar excecao...

			for(unsigned int i=0; i<pessoas.size(); i++)
			{
				if(id==pessoas[i]->getId())
					showMenu("Detalhes da Pessoa", pessoas[i]->imprime());
			}

			system("pause");
			menuPessoas();//volta ao menu pessoas
			break;
		case 3://editar Pessoa
			listaPessoas();
			cout<<endl<<"Introduza o ID da Pessoa que pretende editar: ";
			id=intinput();
			for(unsigned int i=0; i<pessoas.size(); i++)
				if(id == pessoas[i]->getId())
					p = pessoas[i];

			editPessoas(p);
			menuPessoas();
			break;
		case 4://apagar Pessoa
			listaPessoas();
			cout<<endl<<"Introduza o ID da Equipa que pretende apagar: ";
			id=intinput();

			/*
				excepcoes de caso nao encontra a Pessoa.
			*/

			for(unsigned int i=0; i<pessoas.size(); i++)
				if(id == pessoas[i]->getId())
					p = pessoas[i];
			showMenu("Detalhes da Pessoa", p->imprime());
			system("pause");
			removePessoa(id);
			menuPessoas();
			break;
		case 5://importar pessoas
			system("cls");
			cout<<"   --Importar Pessoas--"<<endl<<endl;
			cout<<"Nome do ficheiro: ";
			getline(cin, filename);
			loadPessoas(filename);
			system("pause");
			menuPessoas();
			break;
		case 6://exportar pessoas
			system("cls");
			cout<<"   --Exportar Pessoas--"<<endl<<endl;
			cout<<"Nome do ficheiro para onde vai exportar: ";
			getline(cin, filename);
			savePessoas(filename);
			system("pause");
			menuPessoas();
			break;
		case 0://voltar ao menu anterior
			//saveEqs("equipas.dll", equipas);
			break;
		default:
			cout<<"Opcao invalida! Insira uma das opcoes disponiveis"<<endl;
			system("pause");
			menuPessoas();
		}
	}
	else
	{
		switch(op)
		{
		case 1://criar Pessoa
			cout<<"   --Adicionar Pessoa--"<<endl<<endl;
			addPessoa();
			showMenu("Nova Equipa", pessoas.back()->imprime());
			system("pause");
			menuPessoas();
			break;
		case 2://importar Pessoas
			system("cls");
			cout<<"   --Importar Pessoas--"<<endl<<endl;
			cout<<"Nome do ficheiro: ";
			getline(cin, filename);
		    loadPessoas(filename);
			system("pause");
			menuPessoas();
			break;
		case 0://voltar ao menu anterior
			break;
		default:
			cout<<"Opcao invalida! Insira uma das opcoes disponiveis"<<endl;
			system("pause");
			menuPessoas();
		}
	}
}

void Manutencao::menuMarcacoes()
{
	Marcacao *m;
	int op;
	vector<string> opcoes;
	string filename;
	opcoes.push_back("Escolha uma das seguintes opcoes:");
	opcoes.push_back("");
	opcoes.push_back("1 - Nova Marcacao");//opcao 1
	if(marcacoes.size()>0)
	{
		opcoes.push_back("2 - Ver detalhes de uma Consulta");//opcao 2
		opcoes.push_back("3 - Editar uma Marcacao");//opcao 3
		opcoes.push_back("4 - Apagar uma Marcacao");//opcao 4
		opcoes.push_back("5 - Importar Marcacao dum ficheiro");//opcao 5
		opcoes.push_back("6 - Exportar Marcacao para ficheiro");//opcao 6
	}
	else
		opcoes.push_back("2 - Importar Marcacao do ficheiro");
	opcoes.push_back("");
	opcoes.push_back("0 - Voltar atras");

	showMenu("Gestao de Marcacao", opcoes);
	cout<<"    Opcao: ";
	op=intinput();
	system("cls");

	if(marcacoes.size()>0)
	{
		switch(op)
		{
		case 1:
			cout<<"   --Adicionar Marcacao--"<<endl<<endl;
			addMarcacao();
			showMenu("Nova Marcacao", marcacoes.back()->imprime());
			system("pause");
			menuMarcacoes();
			break;
		case 2://ver detalhes marcacoes
			listaMarcacoes();
			cout<<endl<<"Introduza o ID da Marcacao que pretende ver os detalhes: ";
			int id;
			id=intinput();

			//falta implementar excecao...

			for(unsigned int i=0; i<marcacoes.size(); i++)
			{
				if(id==marcacoes[i]->getId())
				showMenu("Detalhes da Marcacao", marcacoes[i]->imprime());
			}

			system("pause");
			menuMarcacoes();//volta ao menu marcacoes
			break;
		case 3://editar Marcacao
			listaMarcacoes();
			cout<<endl<<"Introduza o ID da Marcacao que pretende editar: ";
			id=intinput();
			for(unsigned int i=0; i<marcacoes.size(); i++)
				if(id == marcacoes[i]->getId())
					m = marcacoes[i];

			editMarcacoes(m);
			menuMarcacoes();
			break;
		case 4://apagar marcacao
			listaMarcacoes();
			cout<<endl<<"Introduza o ID da Marcacao que pretende apagar: ";
			id=intinput();

			/*
				excepcoes de caso nao encontra a Pessoa.
			 */

			for(unsigned int i=0; i<marcacoes.size(); i++)
				if(id == marcacoes[i]->getId())
						m = marcacoes[i];
			showMenu("Detalhes da Marcacao", m->imprime());
			system("pause");
			removeMarcacao(id);
			menuMarcacoes();
			break;
		case 5://importar marcacoes
			system("cls");
			cout<<"   --Importar Marcacoes--"<<endl<<endl;
			cout<<"Nome do ficheiro: ";
			getline(cin, filename);
			loadMarcacoes(filename);
			system("pause");
			menuMarcacoes();
			break;
		case 6://exportar marcacoes
			system("cls");
			cout<<"   --Exportar Marcacoes--"<<endl<<endl;
			cout<<"Nome do ficheiro para onde vai exportar: ";
			getline(cin, filename);
			saveMarcacoes(filename);
			system("pause");
			menuMarcacoes();
			break;

		case 0://voltar ao menu anterior
			break;
		default:
			cout<<"Opcao invalida! Insira uma das opcoes disponiveis"<<endl;
			system("pause");
			menuMarcacoes();
		}
	}
	else
	{
		switch(op)
		{
		case 1:
			cout<<"   --Adicionar Marcacao--"<<endl<<endl;
			addMarcacao();
			showMenu("Nova Marcacao", marcacoes.back()->imprime());
			system("pause");
			menuMarcacoes();
			break;
		case 2://importar Pessoas
			system("cls");
			cout<<"   --Importar Marcacoes--"<<endl<<endl;
			cout<<"Nome do ficheiro: ";
			getline(cin, filename);
			loadMarcacoes(filename);
			cout<<"marcacao size: "<<marcacoes.size()<<endl;
			system("pause");
			menuMarcacoes();
			break;


		case 0://voltar ao menu anterior
			break;
		default:
			cout<<"Opcao invalida! Insira uma das opcoes disponiveis"<<endl;
			system("pause");
			menuMarcacoes();
			}
	}

}

void Manutencao::addPessoa()
{
	string nome, dataNas, tipo, esp, hor, mor, car;
	//stringstream ss;
	double venc;
	//int dia, mes, ano;
	cout<<"Tipo da Pessoa(Medico, Doente ou Funcionario):\n";// (0 para voltar);
	getline(cin, tipo);
	//if(tipo=="0")	//quando sair daqui, no menuPessoas 0 voltar termina sempre o programa,
		//menuPessoas();  //se sem isto funcina bem, nao sei porque
	if(tipo=="Medico")
	{
		cout<<"Nome da Pessoa: ";
		getline(cin, nome);

		cout<<"Data de Nascimento(dia, mes, ano) (separado com espaco, ex: 23 08 2010):\n";
		dataNas=inserirData(dataNas);


		///////////////////////////////
		//  excepcoes dataInvalido() //
		///////////////////////////////

		cout<<"Especialidade: ";
		getline(cin, esp);
		
		hor=inserirHorario(hor);

		///////////////////////////////
		//  excepcoes horaInvalido() //
		///////////////////////////////
		
		/*cout<<"Vencimento: ";
		cin>>venc;
		cin.ignore();*/
		venc = inserirVencimento();

		Medico * m = new Medico(nome, dataNas, tipo, esp, hor, venc);
		pessoas.push_back(m);

		/*string s;
		cout<<"Pretende de associar um Funcionario agora(s/n)? ";
		getline(cin, s);
		if(s=="s")
			associarFuncionario();
		else
			return;*/
	}

	else if (tipo=="Doente")
	{
		cout<<"Nome da Pessoa: ";
		getline(cin, nome);
		cout<<"Data de Nascimento(dia, mes, ano) (separado com espaco, ex: 23 08 2010):\n";
		dataNas=inserirData(dataNas);
		cout<<"Morada: ";
		getline(cin, mor);
		Doente * d = new Doente(nome, dataNas, tipo, mor);
		pessoas.push_back(d);
	}
	else if (tipo=="Funcionario")
	{
		cout<<"Nome da Pessoa: ";
		getline(cin, nome);
		cout<<"Data de Nascimento(dia, mes, ano) (separado com espaco, ex: 23 08 2010):\n";
		dataNas=inserirData(dataNas);
		cout<<"Cargo: ";
		getline(cin, car);
		venc = inserirVencimento();
		Funcionario * f = new Funcionario(nome, dataNas, tipo, car, venc);
		pessoas.push_back(f);
	}
	else
	{
		cout<<"Tipo nao e valido, tenta novamente!\n\n";
		addPessoa();
	}

	cout<<endl;
}

void Manutencao::removePessoa(int id){

	int indice;
	for(unsigned int i=0; i<pessoas.size(); i++)
		if(id == pessoas[i]->getId())
			indice = i;
	int op;
	vector<string> opcoes;
	opcoes.push_back("Tem a certeza que quer apagar a Pessoa?");
	opcoes.push_back("");
	opcoes.push_back("1 - Nao");
	opcoes.push_back("2 - Sim");
	showMenu("Apagar Pessoa", opcoes);
	cout<<"    Opcao: ";
	op=intinput();

	switch(op)
	{
	case 1:
		break;
	case 2:
		pessoas.erase(pessoas.begin()+indice);
		break;
	default:
		cout<<"Opcao invalida! Insira uma das opcoes disponiveis"<<endl;
		system("pause");
		removePessoa(id);
	}
}

void Manutencao::addMarcacao()
{

	stringstream s;
	vector<string> v;
	string tipo, data, hora, sala;
	cout<<"Tipo de Marcacao(Consulta ou Exame): ";
	getline(cin, tipo);
	if(tipo=="Consulta")
	{
		cout<<"Data da Consulta: ";
		data=inserirData(data);
		cout<<"Hora da Consulta: ";
		getline(cin, hora);
		Consulta * c = new Consulta(data, hora, tipo);
		marcacoes.push_back(c);
	}
	else if(tipo=="Exame")
	{
		cout<<"Data do Exame: ";
		getline(cin, data);
		cout<<"Hora do Exame: ";
		getline(cin, hora);
		cout<<"Sala do Exame: ";
		getline(cin, sala);
		Exame * e = new Exame(data, hora, tipo, sala);
		marcacoes.push_back(e);
	}
	else
	{
		cout<<"Tipo nao e valido, tenta novamente!\n\n";
		addMarcacao();
	}
}

void Manutencao::removeMarcacao(int id)
{
	int indice;
	for(unsigned int i=0; i<marcacoes.size(); i++)
		if(id == marcacoes[i]->getId())
			indice = i;
	int op;
	vector<string> opcoes;
	opcoes.push_back("Tem a certeza que quer apagar a Marcacao?");
	opcoes.push_back("");
	opcoes.push_back("1 - Nao");
	opcoes.push_back("2 - Sim");
	showMenu("Apagar Marcacao", opcoes);
	cout<<"    Opcao: ";
	op=intinput();

	switch(op)
	{
	case 1:
		break;
	case 2:
		marcacoes.erase(marcacoes.begin()+indice);
		break;
	default:
		cout<<"Opcao invalida! Insira uma das opcoes disponiveis"<<endl;
		system("pause");
		removeMarcacao(id);
	}
}


void Manutencao::listaPessoas()
{
	system("cls");
	cout<<"  --Pessoas no sistema--"<<endl<<endl;
	vector<Pessoa *>::iterator it=pessoas.begin();

	cout<<"\t|ID| Nome |\n\n";
	cout<<"Medico: "<<endl;
	while(it!=pessoas.end())
	{
		if((*it)->getTipo() == "Medico")
		{
			cout<<"\t"<<(*it)->toList()<<endl;
		}
		it++;
	}
	cout<<"\nDoente: "<<endl;
	it=pessoas.begin();
	while(it!=pessoas.end())
	{
		if((*it)->getTipo() == "Doente")
		{
			cout<<"\t"<<(*it)->toList()<<endl;
		}
		it++;
	}
	cout<<"\nFuncionario: "<<endl;
	it=pessoas.begin();
	while(it!=pessoas.end())
	{
		if((*it)->getTipo() == "Funcionario")
		{
			cout<<"\t"<<(*it)->toList()<<endl;
		}
		it++;
	}

	cout<<endl;
}

void Manutencao::listaMarcacoes()
{
	system("cls");
	cout<<"  --Marcacoes no sistema--"<<endl<<endl;
	vector<Marcacao *>::iterator it=marcacoes.begin();

	cout<<"\t|ID|\n\n";
	cout<<"Consulta: "<<endl;
	while(it!=marcacoes.end())
	{
		if((*it)->getTipo() == "Consulta")
		{
			cout<<"\t"<<(*it)->toList()<<endl;
		}
		it++;
	}
	cout<<"\nExame: "<<endl;
	it=marcacoes.begin();
	while(it!=marcacoes.end())
	{
		if((*it)->getTipo() == "Exame")
		{
			cout<<"\t"<<(*it)->toList()<<endl;
		}
		it++;
	}

	cout<<endl;
}

void Manutencao::editPessoas(Pessoa *p)
{

	vector<string> opcoes;
	string nome, dataNas, tipo, esp, hor, morada, cargo;
	double venc;
	stringstream ss;
	int op;

	opcoes = p->editPessoa();
	for(unsigned int i=0; i<opcoes.size(); i++)
	{
		ss<<opcoes[i]<<endl;
	}
	opcoes.push_back("");
	opcoes.push_back("0 - Voltar atras");

	showMenu("Editar Pessoa", opcoes);
	cout<<"    Opcao: ";
	op=intinput();

	if(p->getTipo()=="Medico")
	{
		switch(op)
		{
		case 1:
		//	system("cls");
		//	cout<<"   --Editar Medico--"<<endl<<endl;
		//	cout<<"Nome de Medico: "<<p->getName()<<endl;
			cout<<"Novo nome de Medico: ";
			getline(cin, nome);
			p->setName(nome);
			editPessoas(p);
			break;
		case 2:
		//	system("cls");
		//	cout<<"   --Editar Medico--"<<endl<<endl;
			cout<<"Novo Data de Nascimento de Medico: ";
			dataNas=inserirData(dataNas);
			p->setDataNascimento(dataNas);
			editPessoas(p);
			break;
	/*	case 3:
		//	system("cls");
		//	cout<<"   --Editar Medico--"<<endl<<endl;
			cout<<"Novo Tipo da Medico: ";
			getline(cin, tipo);
			p->setTipo(tipo);
			editPessoas(p);
			break;*/

		case 3:
			//system("cls");
			//cout<<"   --Editar Medico--"<<endl<<endl;
			cout<<"Novo Especialidade de Medico: ";
			getline(cin, esp);
			p->setEspecialidade(esp);
			editPessoas(p);
			break;
		case 4:
		//	system("cls");
			//cout<<"   --Editar Medico--"<<endl<<endl;
			hor=inserirHorario(hor);
			p->setHorario(hor);
			editPessoas(p);
			break;
		case 5:
			//system("cls");
			//cout<<"   --Editar Medico--"<<endl<<endl;
			venc=inserirVencimento();
			p->setVencimento(venc);
			editPessoas(p);
			break;
		case 0:
			break;
		default:
			editPessoas(p);

		}
	}
	else if(p->getTipo()=="Doente")
	{
		switch(op)
		{
		case 1:
			//system("cls");
			//cout<<"   --Editar Doente--"<<endl<<endl;
			cout<<"Nome de Doente: "<<p->getName()<<endl;
			cout<<"Novo nome de Doente: ";
			getline(cin, nome);
			p->setName(nome);
			editPessoas(p);
			break;
		case 2:
			//system("cls");
			//cout<<"   --Editar Doente--"<<endl<<endl;
			cout<<"Novo Data de Nascimento de Doente: ";
			dataNas = inserirData(dataNas);
			p->setDataNascimento(dataNas);
			editPessoas(p);
			break;
	/*	case 3:
			system("cls");
			cout<<"   --Editar Doente--"<<endl<<endl;
			cout<<"Novo Tipo da Doente: ";
			getline(cin, tipo);
			p->setTipo(tipo);
			editPessoas(p);
			break;*/

		case 3:
			//system("cls");
			//cout<<"   --Editar Doente--"<<endl<<endl;
			cout<<"Novo Morada de Doente: ";
			getline(cin, morada);
			p->setMorada(morada);
			editPessoas(p);
			break;
		case 0:
			break;
		default:
			editPessoas(p);

		}
	}

	else if(p->getTipo()=="Funcionario")
	{

		switch(op)
		{
		case 1:
			//system("cls");
			//cout<<"   --Editar Funcionario--"<<endl<<endl;
			//cout<<"Nome de Funcionario: "<<p->getName()<<endl;
			cout<<"Novo nome de Funcinario: ";
			getline(cin, nome);
			p->setName(nome);
			editPessoas(p);
			break;
		case 2:
			//system("cls");
			//cout<<"   --Editar Funcionario--"<<endl<<endl;
			cout<<"Novo Data de Nascimento de Funcionario: ";
			dataNas=inserirData(dataNas);
			p->setDataNascimento(dataNas);
			editPessoas(p);
			break;
	/*	case 3:
			//system("cls");
			//cout<<"   --Editar Funcionario--"<<endl<<endl;
			cout<<"Novo Tipo da Funcionario: ";
			getline(cin, tipo);
			p->setTipo(tipo);
			editPessoas(p);
			break;*/

		case 3:
			//system("cls");
			//cout<<"   --Editar Funcionario--"<<endl<<endl;
			cout<<"Novo cargo de Funcionario: ";
			getline(cin, cargo);
			p->setCargo(cargo);
			editPessoas(p);
			break;
		case 4:
			//system("cls");
			//cout<<"   --Editar Funcionario--"<<endl<<endl;
			venc=inserirVencimento();
			p->setVencimento(venc);
			editPessoas(p);
			break;
		case 0:
			break;
		default:
			editPessoas(p);

		}
	}
}

void Manutencao::editMarcacoes(Marcacao * m)
{
	vector<string> opcoes;
	string data, hora, tipo, sala;
	stringstream ss;
	int op;

	opcoes = m->editMarcacao();
	for(unsigned int i=0; i<opcoes.size(); i++)
	{
		ss<<opcoes[i]<<endl;
	}
	opcoes.push_back("");
	opcoes.push_back("0 - Voltar atras");

	showMenu("Editar Marcacao", opcoes);
	cout<<"    Opcao: ";
	op=intinput();

	if(m->getTipo()=="Consulta")
	{
		switch(op)
		{
		case 1:
		//	system("cls");
		//	cout<<"   --Editar Medico--"<<endl<<endl;
		//	cout<<"Nome de Medico: "<<p->getName()<<endl;
			cout<<"Novo data de Consulta: ";
			data=inserirData(data);
			m->setData(data);
			editMarcacoes(m);
			break;
		case 2:
		//	system("cls");
		//	cout<<"   --Editar Medico--"<<endl<<endl;
			cout<<"Novo Hora de Consulta: ";
			getline(cin, hora);
			m->setHora(hora);
			editMarcacoes(m);
			break;
		case 3:
		//	system("cls");
		//	cout<<"   --Editar Medico--"<<endl<<endl;
			cout<<"Novo Tipo da Marcacao: ";
			getline(cin, tipo);
			m->setTipo(tipo);
			editMarcacoes(m);
			break;
		case 0:
			break;
		default:
			editMarcacoes(m);
		}
	}
	else if(m->getTipo()=="Exame")
	{
		switch(op)
		{
		case 1:
			//system("cls");
			//cout<<"   --Editar Doente--"<<endl<<endl;
			//cout<<"Nome de Doente: "<<p->getName()<<endl;
			cout<<"Novo data de Exame: ";
			data=inserirData(data);
			m->setData(data);
			editMarcacoes(m);
			break;
		case 2:
			//system("cls");
			//cout<<"   --Editar Doente--"<<endl<<endl;
			cout<<"Novo hora de Exame: ";
			data=inserirData(data);
			m->setHora(hora);
			editMarcacoes(m);
			break;
		case 3:
			//system("cls");
			//cout<<"   --Editar Doente--"<<endl<<endl;
			cout<<"Novo Tipo da Marcacao: ";
			getline(cin, tipo);
			m->setTipo(tipo);
			editMarcacoes(m);
			break;
		case 4:
			//system("cls");
			//cout<<"   --Editar Doente--"<<endl<<endl;
			cout<<"Novo Sala de Exame: ";
			getline(cin, sala);
			m->setSala(sala);
			editMarcacoes(m);
			break;
		case 0:
			break;
		default:
			editMarcacoes(m);
		}
	}
}

void Manutencao::loadPessoas(string filename)
{
	stringstream s;
	unsigned int size;
	string linha;
	vector<string> v;
	ifstream myfile (filename.c_str());
	if(myfile.is_open())
	{
		getline(myfile, linha);
		s<<linha;
		s>>size;//primeira linha com numero de pessoas

		/*
		 * falta implementar a excepcao
		 */

		if(size>0)
		{
			for(unsigned int i=0; i<size; i++)
			{
				getline(myfile, linha);
				v=split('|', linha);
				if(v[3]=="Medico")
				{
					double venc = atof(v[6].c_str());
					Medico *m = new Medico(v[1].c_str(),v[2].c_str(),v[3].c_str(),v[4].c_str(),v[5].c_str(),venc);
					pessoas.push_back(m);
				}
				else if(v[3]=="Doente")
				{
					Doente *d = new Doente(v[1].c_str(),v[2].c_str(),v[3].c_str(),v[4].c_str());
					pessoas.push_back(d);
				}
				else if(v[3]=="Funcionario")
				{
					double venc = atof(v[5].c_str());
					Funcionario *f = new Funcionario(v[1].c_str(),v[2].c_str(),v[3].c_str(),v[4].c_str(), venc);
					pessoas.push_back(f);
				}
			}
			cout<<endl<<endl<<"Pessoas importadas com sucesso!"<<endl<<endl;
		}
		myfile.close();
	}
	else
	{
		cout<<"Nao foi possivel abrir o ficheiro "<<filename<<"!"<<endl<<endl;
	}

}

void Manutencao::savePessoas(string filename)
{
	vector<Pessoa *>::iterator it;

	ofstream myfile (filename.c_str());
	if(myfile.is_open())
	{
		myfile<<pessoas.size()<<endl;
		/*myfile<<"Medico:\n";
		for(it=pessoas.begin(); it!=pessoas.end(); it++)
			if((*it)->getTipo()=="Medico")
				myfile<<(*it)->toString()<<endl;
		myfile<<"\nDoente:\n";
		for(it=pessoas.begin(); it!=pessoas.end(); it++)
			if((*it)->getTipo()=="Doente")
				myfile<<(*it)->toString()<<endl;
		myfile<<"\nFuncionario:\n";
		for(it=pessoas.begin(); it!=pessoas.end(); it++)
			if((*it)->getTipo()=="Funcionario")
				myfile<<(*it)->toString()<<endl;*/

		for(it=pessoas.begin(); it!=pessoas.end(); it++)
			myfile<<(*it)->toString()<<endl;

		myfile.close();
		cout<<endl<<endl<<"Pessoas exportadas com sucesso!"<<endl;
	}
	else
	{
		cout<<"Nao foi possivel abrir o ficheiro!"<<endl<<endl;
		system("pause");
	}
}

void Manutencao::loadMarcacoes(string filename)
{
	stringstream s;
	unsigned int size;
	string linha;
	vector<string> v;
	ifstream myfile (filename.c_str());
	if(myfile.is_open())
	{
		getline(myfile, linha);
		s<<linha;
		s>>size;//primeira linha com numero de pessoas

		/*
		 * falta implementar a excepcao
		 */

		if(size>0)
		{
			for(unsigned int i=0; i<size; i++)
			{
				getline(myfile, linha);
				v=split('|', linha);
				if(v[3]=="Consulta")
				{
					Consulta *c = new Consulta(v[1].c_str(),v[2].c_str(),v[3].c_str());
					marcacoes.push_back(c);
				}
				else if(v[3]=="Exame")
				{
					Exame *e = new Exame(v[1].c_str(),v[2].c_str(),v[3].c_str(),v[4].c_str());
					marcacoes.push_back(e);
				}
			}
			cout<<endl<<endl<<"Marcacoes importadas com sucesso!"<<endl<<endl;
		}
		myfile.close();
	}
	else
	{
		cout<<"Nao foi possivel abrir o ficheiro "<<filename<<"!"<<endl<<endl;
	}
}

void Manutencao::saveMarcacoes(string filename)
{
	vector<Marcacao *>::iterator it;

	ofstream myfile (filename.c_str());
	if(myfile.is_open())
	{
		myfile<<marcacoes.size()<<endl;

		for(it=marcacoes.begin(); it!=marcacoes.end(); it++)
			myfile<<(*it)->toString()<<endl;

		myfile.close();
		cout<<endl<<endl<<"Marcacoes exportadas com sucesso!"<<endl;
	}
	else
	{
		cout<<"Nao foi possivel abrir o ficheiro!"<<endl<<endl;
		system("pause");
	}
}

void Manutencao::saveManutencao()
{
	savePessoas("pessoas.dll");
	saveMarcacoes("marcacoes.dll");
}

void Manutencao::startManutencao()
{
	loadPessoas("pessoas.dll");
	loadMarcacoes("marcacoes.dll");
	welcome();
	menuPrincipal();
}
/*
void Manutencao::associarFuncionario()
{
	Medico m;
	vector<Funcionario *> funs;
	vector<Funcionario *>::iterator it_f;
	int id;

	system("cls");
	cout<<"  --Funcionarios no sistema--"<<endl<<endl;
	vector<Pessoa *>::iterator it=pessoas.begin();

	cout<<"\t|ID| Nome |\n\n";
		cout<<"\nFuncionario: "<<endl;
	it=pessoas.begin();
	while(it!=pessoas.end())
	{
		if((*it)->getTipo() == "Funcionario")
		{
			cout<<"\t"<<(*it)->toList()<<endl;
			Funcionario *f = new Funcionario((*it)->getName(), (*it)->getDataNascimento(), (*it)->getTipo(), (*it)->getCargo(), (*it)->getVencimento());
			funs.push_back(f);
		}
		it++;
	}
	cout<<endl;

	cout<<"Insere o ID do funcionario que pretende de associar: ";
	id = intinput();

	for(it_f=funs.begin(); it_f!=funs.end(); it_f++)
	{
		if(id==(*it_f)->getId())
			m.setFuncionario(*it_f);
			
	}
	

}*/



/*string Manutencao::imprime(){

	return  NULL;
}*/
