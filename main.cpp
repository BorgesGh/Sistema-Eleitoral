#include <iostream>
#include <stdlib.h>
#include "ListaCandidatos.h"

int lerResposta() {
	int aux;
	std::cout << "Insira o valor desejado: ";
	std::cin >> aux;
	return aux;
}

int main() {

	bool verificador = true;
	int resposta;
	ListaCandidatos Lista;

	while (verificador) {
		system("cls");
		std::cout << "\n1 - INSERIR";
		std::cout << "\n2 - REMOVER";
		std::cout << "\n3 - EDITAR";
		std::cout << "\n4 - PESQUISAR POR NUMERO";
		std::cout << "\n5 - IMPRIMIR MAIS VOTADO";
		std::cout << "\n6 - IMPRIMIR TODOS";
		std::cout << "\n0 - Sair";
		std::cout << "\nSelecione uma opcao: ";
		std::cin >> resposta;

		switch (resposta) {

		case 1:
			Lista.inserirCandidato();
			break;
		case 2:
			Lista.removerCandidato(lerResposta());
			break;
		case 3:
			Lista.editarVotosCandidato(lerResposta());
			break;
		case 4:
			Lista.pesquisarCandidato(lerResposta());
			break;
		case 5:
			Lista.imprimirMaisVotado();
			break;
		case 6:
			Lista.imprimirTodosCandidatos();
			break;
		case 0:
			verificador = false;
			break;
		default:
			std::cout << "Resposta invalida!!";
		}
		std::cout << "\n\n";
		system("PAUSE");
	}
}