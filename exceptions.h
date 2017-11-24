#pragma once 
#include <iostream>
#include <iomanip>
#include <string>
#include "castings.h"

class ExcecaoPessoa {
	string nome;
protected:
	ExcecaoPessoa();
	ExcecaoPessoa(string nome);
	friend ostream & operator<<(ostream &os, const ExcecaoPessoa & p1);
	virtual void handler();
};

class ExcecaoSessao {
	int id;
protected:
	ExcecaoSessao();
	ExcecaoSessao(int id);
	friend ostream & operator<<(ostream &os, const ExcecaoSessao & s1);
	virtual void handler();
};

class CandidatoRepetido : public ExcecaoPessoa {
public:
	CandidatoRepetido(Candidato * c);
	CandidatoRepetido(string nome);
	void handler();
};

class CandidatoInexistente : public ExcecaoPessoa {
public:
	CandidatoInexistente(Candidato * c);
	CandidatoInexistente(string nome);
	void handler();
};

class JuradoRepetido : public ExcecaoPessoa {
public:
	JuradoRepetido(Jurado * j);
	JuradoRepetido(string nome);
	void handler();
};

class JuradoInexistente : public ExcecaoPessoa {
public:
	JuradoInexistente(Jurado * j);
	JuradoInexistente(string nome);
	void handler();
};

class SessaoInexistente : public ExcecaoSessao{
public:
	SessaoInexistente(Sessao  &s);
	void handler();
};
class SessaoRepetida : public ExcecaoSessao {
public:
	SessaoRepetida();
	void handler();
};
class JuradosCompleto : public ExcecaoPessoa{
public:
	JuradosCompleto();
	void handler();
};
class JuradoPresente : public ExcecaoPessoa{
public:
	JuradoPresente(Jurado * j);
	JuradoPresente(string nome);
	void handler();
};
class JuradosIncompleto :public ExcecaoSessao {
public:
	JuradosIncompleto(int id);
	void handler();
};
