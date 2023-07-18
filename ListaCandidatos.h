#pragma once
#include "Candidato.h"
//Declarações da classe que será lista encadeada de candidatos

class ListaCandidatos {
private:
	int numCandidatos;
	int totalVotos;
	Candidato* candidatoMaisVotado;
	//    Lista Encadeada
	Candidato* cabecaLista;
	Candidato* fim;

public:
	ListaCandidatos() {
		numCandidatos = 0;
		totalVotos = 0;
		candidatoMaisVotado = NULL;
		cabecaLista = NULL;
		fim = NULL;
	}

	void inserirCandidato(void);
	void removerCandidato(int numeroCandidato);
	void editarVotosCandidato(int numeroCandidato);
	void pesquisarCandidato(int numeroCandidato);
	void imprimirTodosCandidatos(void);
	void imprimirMaisVotado(void);

private:
	Candidato* leituraCandidato(void);
	void calcularPorcentagem(void);
	Candidato* buscarCandidato(int numeroCandidato);
	bool verificarNumero(int);
	void buscarMaisVotado(void);
	void imprimirCandidato(Candidato*);
};