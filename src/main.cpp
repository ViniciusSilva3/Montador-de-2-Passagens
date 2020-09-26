#include <bits/stdc++.h>
#include "leitordearquivos.hpp"
#include "montador.hpp"
#include "testes.hpp"
using namespace std;

int main(int argc, char* argv[]) {
	montador mont1;
	string nomeArquivoFinal;
	if(argc != 3) {
		printf("Parametros de entrada incorretos!\n");
		return 0;
	}
	//testeMontador(mont1);
	nomeArquivoFinal = argv[2];
	nomeArquivoFinal = nomeArquivoFinal.substr(0, nomeArquivoFinal.find('.'));
	if(strcmp(argv[1], "-p") == 0) {
		nomeArquivoFinal += ".PRE";
	}
	else if(strcmp(argv[1], "-o") == 0){
		nomeArquivoFinal += ".OBJ";
	}
	else {
		printf("Diretiva nao encontrada\n");
		return 0;
	}
	EscreveArquivoPreProcessado(argv[2], mont1);
	//test("FAT:    SUB        ONE");
	return 0;
}
