﻿/*#include <iostream>
#include <iomanip>
#include "castings.h"
#include "menus.h"
using namespace std;
void clearScreen()
{
	cout << string(50, '\n');
}
/*int main() {
	//Funcaoo para ler ficheiros .txt
	/*cout << endl << "Insira o nome do ficheiro de candidatos" << endl;
	cout << "::: ";
	string nomeficheirocandidatos;
	cin >> nomeficheirocandidatos;
	ifstream ficheirocand(nomeficheirocandidatos);
	while (!ficheirocand)
	{
		cout << "\n";
		cout << "Ficheiro indisponível. Tente novamente" << endl;;
		cout << "::: ";
		cin >> nomeficheirocandidatos;
		ficheirocand.open(nomeficheirocandidatos);
	}


	string nomeficheirojurados;
	cout << endl << "Insira o nome do ficheiro de jurados" << endl;
	cout << "::: ";
	cin >> nomeficheirojurados;
	ifstream ficheiroju(nomeficheirojurados);
	while (!ficheiroju)
	{
		cout << "\n";
		cout << "Ficheiro indisponível. Tente novamente" << endl;
		cout << "::: ";
		cin >> nomeficheirojurados;
		ficheiroju.open(nomeficheirojurados);
	}
	string nomeficheiroSessoes;
	cout << endl << "Insira o nome do ficheiro de jurados" << endl;
	cout << "::: ";
	cin >> nomeficheiroSessoes;
	ifstream ficheiroSe(nomeficheiroSessoes);
	while (!ficheiroSe)
	{
		cout << "\n";
		cout << "Ficheiro indisponível. Tente novamente" << endl;
		cout << "::: ";
		cin >> nomeficheiroSessoes;
		ficheiroSe.open (nomeficheiroSessoes);
	}
	clearScreen();
//	Castings C(nomeficheirocandidatos, nomeficheirojurados, nomeficheiroSessoes);
	int k; cin >> k;
	
	Castings C("Candidatos.txt", "Jurados.txt", "Sessoes.txt", "Pontuacoes.txt");
	C.setUpCandidatos();
	C.setUpJurados();
	//C.setUpSessoes();
	C.setUpPontuacoes();
	cin >> k;
	//Funcao para tratar do Menu Principal
	Menu_Principal(C);
	system("PAUSE");

	return 0;
}*/
