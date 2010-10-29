///////////////////////////////////////////////////////////
//  Manutencao.cpp
//  Implementation of the Class Manutencao
//  Created on:      24-Out-2010 20:04:12
//  Original author: Answer
///////////////////////////////////////////////////////////

#include "Manutencao.h"
#include "Excecoes.h"
#include "funcoes.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

Manutencao::~Manutencao(){

}

void inserirTipo()
{
	string tipo;
	getline(cin, tipo);
	if(tipo!="Medico"&&tipo!="Doente"&&tipo!="Funcionario")
		throw tipoInvalido(tipo);
}




Manutencao::Manutencao(){

}

/*
void Manutencao::addPessoa(Pessoa * p){


	this->pessoas.push_back(p);
}*/


/*void Manutencao::removePessoa(int id){

	vector<Pessoa>::iterator it;
	for(it=pessoas.begin(); it!=pessoas.end(); it++)
	{
		if((*it)->getId() == id)
			pessoas.erase(it);
	}
}


void Manutencao::addMarcacao(Marcacao * mar){

	this->marcacoes.push_back(mar);
}
*/

void Manutencao::removeMarcacao(){

}


string Manutencao::imprime(){

	return  NULL;
}


void Manutencao::load(){

}


void Manutencao::save(){

}

int Manutencao::numPessoas()
{
	return this->pessoas.size();
}

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

    /*try{
    	intinput(op);
    }
    catch(notIntInput(op))
    {
    	cout<<"a opcao tem que ser um inteiro.\n";

    }*/
    switch(op)
    {
    case 1:
        menuPessoas(); //vai para menu equipas
        menuPrincipal(); //volta ao menu principal
        break;
    case 2:
        menuMarcacoes(); //vai para menu estadios
        menuPrincipal(); //volta ao menu principal
        break;
    case 0://vai para funcao de fim para fechar programa
       // fim();
        break;
    default:
        cout<<"Opcao invalida! Insira uma das opcoes disponiveis"<<endl;
        system("pause");
        menuPrincipal();
    }
}



void Manutencao::menuPessoas()
{
	int op;
	Manutencao m;
	vector<string> opcoes;
	string filename;
	opcoes.push_back("Escolha uma das seguintes opcoes:");
	opcoes.push_back("");
	opcoes.push_back("1 - Nova Pessoa");//opcao 1
	if(m.numPessoas()!=0)
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
	if(m.numPessoas()>0)
	{
		switch(op)
		{
		case 1:
			cout<<"   --Adicionar Pessoa--"<<endl<<endl;
			addPessoa();
			showMenu("Nova Pessoa", pessoas.back().imprime());//mostra equipa
			system("pause");
			menuPessoas();//volta ao menu Pessoas
			break;
	/*	case 2://ver detalhes Pessoas
			//listaEqs();
			cout<<endl<<"Introduza o ID da Pessoa que pretende ver os detalhes: ";
			//id=intinput();
			//ind_eq=findIndEq(id);
			while(ind_eq==-1)
			{
				cout<<"A equipa que inseriu nao existe! Tente novamente: ";
				id=intinput();
				ind_eq=findIndEq(id);
			}
			showMenu("Detalhes da Equipa", equipas.at(ind_eq).toDetalhes());
			system("pause");
			menuEquipas();//volta ao menu equipas
			break;
		case 3://editar equipa
			listaEqs();
			cout<<endl<<"Introduza o ID da Equipa que pretende editar: ";
			id=intinput();
			ind_eq=findIndEq(id);
			while(ind_eq==-1)
			{
				cout<<"A equipa que inseriu nao existe! Tente novamente: ";
				id=intinput();
				ind_eq=findIndEq(id);
			}
			editEquipa(&equipas.at(ind_eq));
			menuEquipas();
			break;
		case 4://apagar equipa
			listaEqs();
			cout<<endl<<"Introduza o ID da Equipa que pretende apagar: ";
			id=intinput();
			ind_eq=findIndEq(id);
			while(ind_eq==-1)
			{
				cout<<"A equipa que inseriu nao existe! Tente novamente: ";
				id=intinput();
				ind_eq=findIndEq(id);
			}
			showMenu("Detalhes da Equipa", equipas.at(ind_eq).toDetalhes());
			system("pause");
			delEq(id);
			menuEquipas();
			break;
		case 5://importar equipas
			clear();
			cout<<"   --Importar Equipas--"<<endl<<endl;
			cout<<"Nome do ficheiro: ";
			getline(cin, filename);
			loadEqs(filename);
			system("pause");
			menuEquipas();
			break;
		case 6://exportar equipas
			clear();
			cout<<"   --Exportar Equipas--"<<endl<<endl;
			cout<<"Nome do ficheiro para onde vai exportar: ";
			getline(cin, filename);
			saveEqs(filename, toExportEqs());
			system("pause");
			menuEquipas();
			break;*/
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
			showMenu("Nova Equipa", pessoas.back().imprime());
			system("pause");
			menuPessoas();
			break;
		/*case 2://importar equipas
			clear();
			cout<<"   --Importar Equipas--"<<endl<<endl;
			cout<<"Nome do ficheiro: ";
			getline(cin, filename);
		   loadEqs(filename);
			system("pause");
			menuEquipas();
			break;*/
		case 0://voltar ao menu anterior
			break;
		default:
			cout<<"Opcao invalida! Insira uma das opcoes disponiveis"<<endl;
			system("pause");
			menuPessoas();
		}
	}
}


void Manutencao::menuMarcacoes(){

}

void Manutencao::addPessoa()
{

	Pessoa p;
	Manutencao m;
	string nome, dataNas, tipo, esp, hor, mor, car;
	double venc;
	//clear();
	//cout<<"   --Adicionar Pessoa--"<<endl<<endl;

	cout<<"Tipo da Pessoa(Medico, Doente ou Funcionario): ";
	getline(cin, tipo);
	if(tipo=="Medico")
	{
		cout<<"Nome da Pessoa: ";
		getline(cin, nome);
		cout<<"Data de Nascimento: ";
		getline(cin, dataNas);
		cout<<"Especialidade: ";
		getline(cin, esp);
		cout<<"Horario: ";
		getline(cin, hor);
		cout<<"Vencimento: ";
		cin>>venc;
		pessoas.push_back(Medico(nome,dataNas,tipo, esp, hor,venc));
	}
	if (tipo=="Doente")
	{
		cout<<"Nome da Pessoa: ";
		getline(cin, nome);
		cout<<"Data de Nascimento: ";
		getline(cin, dataNas);
		cout<<"Morada: ";
		getline(cin, mor);
		pessoas.push_back(Doente(nome, dataNas, tipo, mor));
	}
	if (tipo=="Funcionario")
	{
		cout<<"Nome da Pessoa: ";
		getline(cin, nome);
		cout<<"Data de Nascimento: ";
		getline(cin, dataNas);
		cout<<"Cargo: ";
		getline(cin, car);
		cout<<"Vencimento: ";
		cin>>venc;
		pessoas.push_back(Funcionario(nome, dataNas, tipo, car, venc));
	}
	else
	{
		cout<<"Tipo nao e valido, tenta novamente!\n";
		//system("pause");
		cout<<endl;
		addPessoa();
	}

	cout<<endl;
}
