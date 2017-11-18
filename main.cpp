#include <iostream>
#include <iomanip>
#include "castings.h"
#include "menus.h"
#include <fstream>

using namespace std;
void clearScreen()
{
	cout << string(50, '\n');
}

int main() {
	//Funcaoo para ler ficheiros .txt
	cout << endl << "Insira o nome do ficheiro de candidatos" << endl;
	cout << "::: ";
	string nomeficheirocandidatos;
	cin >> nomeficheirocandidatos;
	ifstream ficheirocand(nomeficheirocandidatos);
	ficheirocand.open(nomeficheirocandidatos);

	while (ficheirocand.fail())
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
	ficheiroju.open(nomeficheirojurados);
	
	while (ficheiroju.fail())
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
	ficheiroSe.open(nomeficheiroSessoes);

	while (ficheiroSe.fail())
	{
		cout << "\n";
		cout << "Ficheiro indisponível. Tente novamente" << endl;
		cout << "::: ";
		cin >> nomeficheiroSessoes;
		ficheiroSe.open(nomeficheiroSessoes);
	}

	clearScreen();
	Castings C(nomeficheirocandidatos, nomeficheirojurados, nomeficheiroSessoes);
	C.setUpCandidatos();
	C.setUpJurados();
	C.setUpSessoes();
	//Funcao para tratar do Menu Principal
	Menu_Principal();
	system("PAUSE");

	return 0;
}