///////////////////////////////////////////////////////////
//  Geral.cpp
//  Implementation of the Class Geral
//  Created on:      24-Out-2010 20:04:11
//  Original author: Answer
///////////////////////////////////////////////////////////

#include "Geral.h"
using namespace std;

Geral::Geral(){

}



Geral::~Geral(){

}



void Geral::welcome()
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
	o<<"*                    * * *   *      *   * * *   *   * * *                     *\n";
	o<<"*                   *     *  *         *     *     *     *                    *\n";
	o<<"*                   *        *      *  *     *  *  *                          *\n";
	o<<"*                   *        *      *  *     *  *  *                          *\n";
	o<<"*                   *     *  *   *  *  *     *  *  *     *                    *\n";
	o<<"*                    * * *    * *   *  *     *  *   * * *                     *\n";
	for (unsigned int i=0; i<3; i++)
	{
		o<<"*";
		for(unsigned int j=0; j<77; j++)
			o<<" ";
		o<<"*"<<endl;
	}
	o<<"*       *  * *  *     * *     * * *     * *     * * *   * * * *   * * *       *\n";
	o<<"*      *    *    *   *   *   *     *   *   *   *        *        *     *      *\n";
	o<<"*      *    *    *  *     *  *     *  *     *  *        *        *     *      *\n";
	o<<"*      *    *    *  *     *  *     *  *     *  * * * *  * * * *  * * *        *\n";
	o<<"*      *    *    *  * * * *  *     *  * * * *  * *   *  *        *   *        *\n";
	o<<"*      *    *    *  *     *  *     *  *     *   * * *   * * * *  *     *      *\n";
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

void Geral::showMenu(string titulo, vector<string> opcoes)
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

void Geral::menuPrincipal()
{
    int op, ind_cam, id;
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


void Geral::menuPessoas(){

}


void Geral::menuMarcacoes(){

}

