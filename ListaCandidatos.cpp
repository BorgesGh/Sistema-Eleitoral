#include <iostream>
#include "ListaCandidatos.h"

Candidato* ListaCandidatos::leituraCandidato(void) {
	Candidato* novo;
	novo = (Candidato*)malloc(sizeof(Candidato));
	bool verificador = false;

	novo->ante = NULL;
	novo->prox = NULL;
	novo->porcentagemVotos = 1;

	do {
		std::cout << "\nDigite o NUMERO do candidato: ";
		std::cin >> novo->numero;
		if (verificarNumero(novo->numero) || novo->numero < 0) {
			std::cout << "\nO numero escrito eh invalido!! Digite um diferente";
			verificador = true;
		}
		else 
		{
			verificador = false;
		}

	} while (verificador);

	do {
		std::cout << "\nDigite a Quantidade de votos do candidato: ";
		std::cin >> novo->votos;
		if (novo->votos < 0) {
			std::cout << "\nNumero de votos incompativeis!!!";
			verificador = true;
		}
		else 
		{
			verificador = false;
		}

	} while (verificador);

	numCandidatos++;
	totalVotos += novo->votos;

	return novo;
}
void ListaCandidatos::calcularPorcentagem(void) {
	Candidato* atual;
	atual = cabecaLista;

	while (atual != NULL) {
		atual->porcentagemVotos = ((float)atual->votos / (float)totalVotos) * 100;
		atual = atual->prox;
	}

}
Candidato* ListaCandidatos::buscarCandidato(int numeroCandidato) {
	Candidato* atual;
	atual = cabecaLista;

	while (atual != NULL) {
		if (atual->numero == numeroCandidato)
			return atual;
		atual = atual->prox;
	}
	return NULL;
}
bool ListaCandidatos::verificarNumero(int numeroCandidato) {
	Candidato* verificador;
	verificador = buscarCandidato(numeroCandidato);

	if (verificador != NULL) {
		std::cout << "\nJa existe um candidato com esse numero!!!";
		return true;
	}
	return false;
}
void ListaCandidatos::buscarMaisVotado() {
	Candidato* maisVotado;
	Candidato* atual;

	maisVotado = cabecaLista;
	atual = cabecaLista->prox;

	while (atual != NULL) {
		if (atual->votos > maisVotado->votos) {
			maisVotado = atual;
		}
		atual = atual->prox;
	}

	candidatoMaisVotado = maisVotado;

}
void ListaCandidatos::imprimirCandidato(Candidato* C) {
	std::cout << "\n\nNumero do candidato: " << C->numero;
	std::cout << "\nQuantidade de votos: " << C->votos;
	printf("\nPorcentagem do total de votos: %.2f\n\n", C->porcentagemVotos);
}
void ListaCandidatos::imprimirTodosCandidatos() {
	std::cout << "\n\tAtualmente existem -> " << numCandidatos << " candidatos";
	Candidato* atual;
	atual = cabecaLista;

	while (atual != NULL) {
		imprimirCandidato(atual);
		atual = atual->prox;
	}
}
void ListaCandidatos::imprimirMaisVotado() {
	imprimirCandidato(candidatoMaisVotado);
}
void ListaCandidatos::pesquisarCandidato(int numeroCandidato) {

	Candidato* atual;
	atual = buscarCandidato(numeroCandidato);
	if (atual != NULL)
		imprimirCandidato(atual);
	else
		std::cout << "\nO Candidato nao existe!!";

}


//============================| LISTA ENCADEADA |================================
void ListaCandidatos::inserirCandidato(void) {
	Candidato* novo = leituraCandidato();
	if (cabecaLista == NULL) {
		//A lista esta vazia
		cabecaLista = novo;
		fim = novo;

	}
	else {
		//Insere no final da lista
		fim->prox = novo;
		novo->ante = fim;
		fim = novo;

	}
	calcularPorcentagem();
	buscarMaisVotado();
}

void ListaCandidatos::editarVotosCandidato(int numeroCandidato) {
	Candidato* atual;
	bool verificador = false;
	atual = buscarCandidato(numeroCandidato);
	if (atual != NULL) {
		//candidato encontrado
		totalVotos -= atual->votos;
		do {
			std::cout << "\nDigite o novo valor de votos: ";
			std::cin >> atual->votos;

			if (atual->votos < 0) {
				std::cout << "\n---------| Valor inválido |----------";
				verificador = true;
			}
		} while (verificador);
		totalVotos += atual->votos;
	}//if
	else {
		std::cout << "\nPessoa não encontrada!!";
	}

	calcularPorcentagem();
	buscarMaisVotado();
}

void ListaCandidatos::removerCandidato(int numeroCandidato) {
	if (cabecaLista == NULL) {
		std::cout << "\nA lista esta vazia!!";
	}
	else {
		Candidato* removido;
		removido = buscarCandidato(numeroCandidato);
		if (removido == NULL) {
			std::cout << "\n\tEsse candidato nao existe!!!";
		}
		else {
			numCandidatos--;
			totalVotos -= removido->votos;
			//O candidato existe e sera removido
			if (removido->ante == NULL) {
				//é o primeiro da fila
				cabecaLista = cabecaLista->prox;
				cabecaLista->ante = NULL;

				free(removido);
			}
			else if (removido->prox == NULL) {
				//é o ultimo da fila
				fim = fim->ante;
				fim->prox = NULL;

				free(removido);
			}
			else {
				//Esta no meio
				removido->ante->prox = removido->prox;
				removido->prox->ante = removido->ante;

				free(removido);
			}	
		}//else
	}
	calcularPorcentagem();
	buscarMaisVotado();
}