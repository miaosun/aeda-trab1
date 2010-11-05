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


Manutencao::Manutencao()
{
	especialidades.push_back("Dentaria");
	especialidades.push_back("Ortopedia");
	especialidades.push_back("Oftaumonologia");
	especialidades.push_back("Psiquiatria");
	especialidades.push_back("Cirurgia");
	especialidades.push_back("Imagiologia");
}

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
	opcoes.push_back("3 - Gestao de Especialidades");
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
	case 3:
		menuEspecialidades();
		menuPrincipal();
    case 0:
		saveManutencao();
        break;
    default:
        cout<<"Opcao invalida! Insira uma das opcoes disponiveis"<<endl;
        //menuPrincipal();
    }
}

void Manutencao::menuPessoas()//visto
{
	int op, id;
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
			addPessoa();
			menuPessoas();
			break;
		case 2://ver detalhes Pessoas
			listaPessoas();
			cout<<endl<<"Introduza o ID da Pessoa que pretende ver os detalhes: ";
			id=intinput();

			try
			{
				showMenu("Detalhes da Pessoa", find(&pessoas, id)->imprime());
			}
			catch (NotFound)
			{
				cout<<endl<<"Pessoa nao encontrada!"<<endl;
			}

			system("pause");
			menuPessoas();//volta ao menu pessoas
			break;
		case 3://editar Pessoa
			listaPessoas();
			cout<<endl<<"Introduza o ID da Pessoa que pretende editar: ";
			id=intinput();
			try
			{
				p=find(&pessoas, id);
				editPessoas(p);
			}
			catch (NotFound)
			{
				cout<<endl<<"Pessoa nao encontrada!"<<endl;
				system("pause");
			}
			menuPessoas();
			break;
		case 4://apagar Pessoa
			listaPessoas();
			cout<<endl<<"Introduza o ID da Pessoa que pretende apagar: ";
			id=intinput();

			try
			{
				p=find(&pessoas, id);
				showMenu("Detalhes da Pessoa", p->imprime());
				removePessoa(id);
			}
			catch (NotFound)
			{
				cout<<endl<<"Pessoa nao encontrada!"<<endl;
				system("pause");
			}
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
		case 0:
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
			addPessoa();
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

void Manutencao::menuMarcacoes()//visto
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
		opcoes.push_back("2 - Ver detalhes de uma Marcacao");//opcao 2
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
			addMarcacao();
			menuMarcacoes();
			break;
		case 2://ver detalhes marcacoes
			listaMarcacoes();
			cout<<endl<<"Introduza o ID da Marcacao que pretende ver os detalhes: ";
			int id;
			id=intinput();

			try
			{
				m=find(&marcacoes, id);
				showMenu("Detalhes da Marcacao", m->imprime());
			}
			catch (NotFound)
			{
				cout<<endl<<"Marcacao nao encontrada!"<<endl;
			}

			system("pause");
			menuMarcacoes();//volta ao menu marcacoes
			break;
		case 3://editar Marcacao
			listaMarcacoes();
			cout<<endl<<"Introduza o ID da Marcacao que pretende editar: ";
			id=intinput();

			try
			{
				m=find(&marcacoes, id);
				editMarcacoes(m);
			}
			catch (NotFound)
			{
				cout<<endl<<"Marcacao nao encontrada!"<<endl;
				system("pause");
			}			
			menuMarcacoes();
			break;
		case 4://apagar marcacao
			listaMarcacoes();
			cout<<endl<<"Introduza o ID da Marcacao que pretende apagar: ";
			id=intinput();

			try
			{
				m=find(&marcacoes, id);
				showMenu("Detalhes da Marcacao", m->imprime());
				system("pause");
				removeMarcacao(id);
			}
			catch (NotFound)
			{
				cout<<endl<<"Marcacao nao encontrada!"<<endl;
				system("pause");
			}
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
			addMarcacao();
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

void Manutencao::menuEspecialidades()
{
	vector<string> opcoes;
	int op;
	opcoes.push_back("Escolha uma das seguintes opcoes:");
	opcoes.push_back("");
	opcoes.push_back("1 - Ver Especialidades");
	opcoes.push_back("2 - Nova Especialidade");
	opcoes.push_back("");
	opcoes.push_back("0 - Voltar atras");
	showMenu("Gestao de especialidades", opcoes);
	cout<<"    Opcao: ";
	op=intinput();
	system("cls");

	switch (op)
	{
	case 1:
		listaEspecialidades();
		system("pause");
		menuEspecialidades();
		break;
	case 2:
		addEspecialidade();
		menuEspecialidades();
		break;
	case 0:
		break;
	default:
		menuEspecialidades();
	}
}

string Manutencao::escolheEspecialidade()
{
	int op;
	listaEspecialidades();
	do
	{
		cout<<"Especialidade: ";
		op=intinput();
	}
	while(op<0||op>especialidades.size()-1);
	return especialidades.at(op);
}

void Manutencao::listaEspecialidades()
{
	system("cls");
	for(unsigned int i=0; i<especialidades.size(); i++)
		cout<<i<<" - "<<especialidades.at(i)<<endl;
	cout<<endl;
}

void Manutencao::addEspecialidade()
{
	string esp;
	listaEspecialidades();
	cout<<"Nome da nova especialidade: ";
	cin>>esp;
	especialidades.push_back(esp);
}

void Manutencao::addPessoa()//visto
{
	string nome, dataNas, tipo, esp, hor, mor, car, s;
	vector<string> opcoes;
	double venc;
	int op;
	Medico * m;
	Funcionario * f;
	Doente * d;

	opcoes.push_back("Escolha uma das seguintes opcoes:");
	opcoes.push_back("");
	opcoes.push_back("1 - Novo Medico");
	opcoes.push_back("2 - Novo Funcionario");
	opcoes.push_back("3 - Novo Doente");
	opcoes.push_back("");
	opcoes.push_back("0 - Voltar atras");
	showMenu("Adicionar Pessoa", opcoes);
	cout<<"    Opcao: ";
	op=intinput();
	system("cls");


	switch(op)
	{
	case 1: //medico
		tipo = "Medico";
		cout<<"Nome da Pessoa: ";
		getline(cin, nome);

		cout<<"Data de Nascimento(dia, mes, ano) (separado com espaco, ex: 23 08 2010):\n";
		
		dataNas=inserirData();


		esp=escolheEspecialidade();
		
		hor=inserirHorario();
		
		venc = inserirVencimento();

		m = new Medico(nome, dataNas, tipo, esp, hor, venc);
		pessoas.push_back(m);

		cout<<"Pretende de associar um Funcionario agora(s/n)? ";
		getline(cin, s);
		if(s=="s")
			associarFuncionario(m);
		else
			return;

		break;
	case 2: //funcionario
		tipo = "Funcionario";
		cout<<"Nome da Pessoa: ";
		getline(cin, nome);
		cout<<"Data de Nascimento(dia, mes, ano) (separado com espaco, ex: 23 08 2010):\n";
		dataNas=inserirData();
		cout<<"Cargo: ";
		getline(cin, car);
		venc = inserirVencimento();
		f = new Funcionario(nome, dataNas, tipo, car, venc);
		pessoas.push_back(f);
		break;
	case 3: //doente
		tipo = "Doente";
		cout<<"Nome da Pessoa: ";
		getline(cin, nome);
		cout<<"Data de Nascimento(dia, mes, ano) (separado com espaco, ex: 23 08 2010):\n";
		dataNas=inserirData();
		cout<<"Morada: ";
		getline(cin, mor);
		d = new Doente(nome, dataNas, tipo, mor);
		pessoas.push_back(d);
		break;
	case 0: //sair
	default:
		break;
	}

	if(op==1||op==2||op==3)
	{
		showMenu("Nova Pessoa", pessoas.back()->imprime());
		system("pause");
	}

}

void Manutencao::removePessoa(int id)//visto
{

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

void Manutencao::addMarcacao()//visto
{
	vector<string> opcoes;
	int op;
	stringstream s;
	vector<string> v;
	string tipo, data, hora, sala;
	Consulta * c;
	Exame * e;

	opcoes.push_back("Escolha um dos seguintes tipos de marcacao:");
	opcoes.push_back("");
	opcoes.push_back("1 - Consulta");
	opcoes.push_back("2 - Exame");
	opcoes.push_back("");
	opcoes.push_back("0 - Voltar atras");
	showMenu("Adicionar Marcacao", opcoes);
	cout<<"    Opcao: ";
	op=intinput();
	system("cls");

	switch(op)
	{
	case 1:
		tipo = "Consulta";
		cout<<"Data da Consulta: ";
		data=inserirData();
		cout<<"Hora da Consulta: ";
		getline(cin, hora);
		c = new Consulta(data, hora, tipo);
		marcacoes.push_back(c);
		break;
	case 2:
		tipo = "Exame";
		cout<<"Data do Exame: ";
		data=inserirData();
		cout<<"Hora do Exame: ";
		getline(cin, hora);
		cout<<"Sala do Exame: ";
		getline(cin, sala);
		e = new Exame(data, hora, tipo, sala);
		marcacoes.push_back(e);
		break;
	case 0:
		return;
		break;
	default:
		addMarcacao();
		break;
	}

	if(op==1||op==2)
	{
		showMenu("Nova Marcacao", marcacoes.back()->imprime());
		system("pause");
	}
}

void Manutencao::removeMarcacao(int id)//visto
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

void Manutencao::listaMedicos()
{
	vector<Pessoa *>::iterator it=pessoas.begin();
	cout<<"Medico: "<<endl;
	while(it!=pessoas.end())
	{
		if((*it)->getTipo() == "Medico")
		{
			cout<<"\t"<<(*it)->toList()<<endl;
		}
		it++;
	}
}

void Manutencao::listaFuncionarios()
{
	vector<Pessoa *>::iterator it=pessoas.begin();
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
}

void Manutencao::listaDoentes()
{
	vector<Pessoa *>::iterator it=pessoas.begin();
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
}

void Manutencao::listaPessoas()//visto
{
	system("cls");
	cout<<"  --Pessoas no sistema--"<<endl<<endl;
	vector<Pessoa *>::iterator it=pessoas.begin();

	cout<<"\t|ID| Nome |\n\n";
	
	listaMedicos();
	listaFuncionarios();
	listaDoentes();

	cout<<endl;
}

void Manutencao::listaMarcacoes()//visto
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

void Manutencao::editPessoas(Pessoa *p)//visto
{
	Medico * m;
	vector<string> opcoes;
	string nome, dataNas, tipo, esp, hor, morada, cargo;
	double venc;
	int op;

	opcoes = p->editPessoa();

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
			dataNas=inserirData();
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
			hor=inserirHorario();
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
		case 6:
			m = new Medico(p->getName(), p->getDataNascimento(), p->getTipo(), p->getEspecialidade(), p->getHorario(), p->getVencimento());
			system("pause");
			associarFuncionario(m);
			editPessoas(m);
			break;
		case 0:
			return;
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
			dataNas = inserirData();
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
			return;
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
			dataNas=inserirData();
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
			return;
			break;
		default:
			editPessoas(p);

		}
	}
}

void Manutencao::editMarcacoes(Marcacao * m)//visto
{
	vector<string> opcoes;
	string data, hora, tipo, sala;
	int op;

	opcoes = m->editMarcacao();

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
			data=inserirData();
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
	/*	case 3:
		//	system("cls");
		//	cout<<"   --Editar Medico--"<<endl<<endl;
			cout<<"Novo Tipo da Marcacao: ";
			getline(cin, tipo);
			m->setTipo(tipo);
			editMarcacoes(m);
			break;*/
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
			cout<<"Nova data de Exame: ";
			data=inserirData();
			m->setData(data);
			editMarcacoes(m);
			break;
		case 2:
			//system("cls");
			//cout<<"   --Editar Doente--"<<endl<<endl;
			cout<<"Nova hora de Exame: ";
			data=inserirData();
			m->setHora(hora);
			editMarcacoes(m);
			break;
		/*case 3:
			//system("cls");
			//cout<<"   --Editar Doente--"<<endl<<endl;
			cout<<"Novo Tipo da Marcacao: ";
			getline(cin, tipo);
			m->setTipo(tipo);
			editMarcacoes(m);
			break;*/
		case 3:
			//system("cls");
			//cout<<"   --Editar Doente--"<<endl<<endl;
			cout<<"Nova Sala de Exame: ";
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
	Pessoa *p;
	Funcionario *f;
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
			/*		p=find(&pessoas,atoi(v[6].c_str()));
					if(p==NULL){system("pause");
					m->setFuncionario(0);cout<<"teste";}
					else
						f = new Funcionario(p->getName(), p->getDataNascimento(), p->getTipo(), p->getCargo(), p->getVencimento());*/
					associarFuncionario(m);
					system("pause");
					cout<<"teste3";
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

void Manutencao::associarFuncionario(Medico *m)
{
	Pessoa *p;
	Funcionario *f;
	int id;
	system("pause");
	system("cls");
	cout<<"  --Funcionarios no sistema--"<<endl<<endl;
	
	listaFuncionarios();

	cout<<"Insere o ID do funcionario que pretende de associar: ";
	id = intinput();
	for(unsigned int i=0; i<pessoas.size(); i++)
	{
		if(pessoas.at(i)->getTipo=="Funcionario"&&pessoas.at(i)->getId()==id)
		{
			m->setFuncionario(p);
			return;
		}
	}
	cout<<"Nao tem nenhum funcionario com esse ID!";
	system("pause");
}



/*string Manutencao::imprime(){

	return  NULL;
}*/
