#pragma once
//Struct que ser� o candidato
typedef struct Candidato {

	int numero;
	int votos;
	float porcentagemVotos;
	struct Candidato* prox;
	struct Candidato* ante;

}Candidato;