#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class Pessoa;
class Jurado;
class Candidato;
class Sessao;
class Pontuacao;
class Castings;
class CandidatoRepetido;
class CandidatoInexistente;
class Data {
private:
	int dia;
	int mes;
	int ano;
public:
	int getDia();
	int getMes();
	int getAno();
	void setDia(int dia);
	void setMes(int mes);
	void setAno(int ano);
	bool operator==(Data &d1);
};
class Pessoa {
protected:
	string nome;
	string morada;
	string genero;
public:
	Pessoa();
	Pessoa(string nome, string morada, string genero);
	string getNome() const;
	string getMorada() const;
	string getGenero() const;
	void setNome(string nome);
	void setMorada(string morada);
	void setGenero(string genero);
	virtual bool operator==(Pessoa &p1);
};

class Jurado : public Pessoa {
private:
	string telemovel;
public:
	Jurado();
	Jurado(string ficheiro_jurados);
	Jurado(string nome, string morada, string genero, string telemovel);
	string getTelemovel() const;
	void setTelemovel(string telemovel);
	bool operator==(Jurado &j1);
	

};
class Candidato : public Pessoa {
private:
	Data data_nascimento;
	static int numInscricao; //atribuido  automaticamente quando realizam a 1�inscricao
	vector<Sessao> sessoes;
	vector<Pontuacao> pontuacoes;
public:
	Candidato();
	Candidato(string ficheiro_candidatos);
	Candidato(string nome, string morada, string genero, Data data_nascimento);
	Data getDataNascimento() const;
	vector<Sessao> getSessoes() const;
	bool operator==(Candidato &c1);
	void adicionarSessao(Sessao &s1);
};
class Pontuacao { //resultados de um candidato numa determinada sess�o e fase
private:
	int id_sessao;
	int fase;
	vector<int> classificacoes; // vetor c/3 posi��es em que �ndice 0 equivale � primeira classifica��o.

public:
	int getId() const;
	int getFase() const;
	vector<int> getClassificacoes() const;
	double getClassificacao() const;

};

class Sessao {
protected:
	 int id;
	int fase; //1 ou 2
	int numMaxCandidatos; 
	int numVagas;
	Jurado responsavel;
	string genero;
	Data data; //A empresa nao organiza mais que uma sessao do mesmo genero por dia
	vector<Jurado*> jurados_sessao; //Cada sessao e composta por 3 jurados
	vector <Candidato*> concorrentes_iniciais; //vector composto por todos os candidatos a 1fase
	vector <Candidato*> concorrentes_finais; //concorrentes que passam  2fase;
public:
	Sessao();
	Sessao(string ficheiro_sessao);
	int getId() const;
	string getGenero() const;
	Data getData();
	Jurado getResponsavel() const;
	vector<Jurado*> & getJurados_sessao();
	vector <Candidato*> & getConcorrentes_iniciais();
	vector <Candidato *> &getConcorrentes_finais();
	int getNumVagas() const;
	bool operator==(Sessao &s1);
	bool eliminaCandidatoSessao(Candidato *c1);
	void setData(Data data);
	void setResponsavel(Jurado j1);
	bool juriCompleto() const;
	bool juradoPresente(Jurado * j1);
};



class Castings {
private:
	vector<Jurado*> jurados;
	vector <Candidato*> candidatos;
	vector<Sessao> sessoes;
	string ficheiroCandidatos;
	string ficheiroJurados;
	string ficheiroSessoes;
public:
	vector <Jurado *> getJurados();
	vector< Candidato*> getCandidatos();
	vector<Sessao> getSessao();
	size_t juradoExiste(Jurado * j1); // retorna -1 se o jurado n�o existir no vetor jurados, retorna o seu indice se existir
	size_t candidatoExiste(Candidato * c1); // retorna -1 se o candidato n�o existir no vetor candidatos, retorna o seu indice se existir
	size_t sessaoExiste(Sessao &s1); // retorna -1 se a sess�o n�o existir no vetor sessoes, retorna o seu indice se existir
	size_t juradoExisteSessao(Jurado * j1, Sessao &s1); // retorna -1 se o jurado n�o existir no vetor jurados_sessao, retorna o seu indice se existir
	void setUpCandidatos();
	void setUpJurados();
	bool adicionaCandidato(Candidato *c1);
	bool adicionaJurado(Jurado *j1);
	bool adicionaCandidatoSessao(Candidato *c1, Sessao &s1);
	bool adicionaJuradoSessao(Jurado *j1, Sessao &s1);
	bool eliminaCandidato(Candidato *c1);
	bool tornaJuradoResponsavel(Jurado * j1, Sessao &s1);
	bool eliminaJurado(Jurado * j1);
	bool eliminaCandidatoSessao(Candidato *c1, Sessao &s1);
};


