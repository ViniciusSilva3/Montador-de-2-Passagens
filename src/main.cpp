#include <bits/stdc++.h>
#include "leitordearquivos.hpp"
#include "montador.hpp"
#include "testes.hpp"
using namespace std;

int main(int argc, char* argv[]) {
	montador mont1;
	string nomeArquivoFinal, nomeArquivoPre;
	if(argc != 3) {
		printf("Parametros de entrada incorretos!\n");
		return 0;
	}
	//testeMontador(mont1);
	nomeArquivoFinal = argv[2];
	nomeArquivoFinal = nomeArquivoFinal.substr(0, nomeArquivoFinal.find('.'));
	nomeArquivoPre = nomeArquivoFinal + ".PRE" + ".txt";
	nomeArquivoFinal += ".OBJ";
	if(strcmp(argv[1], "-p") == 0) {
		
		mont1.flagPreProcess = 0;
	}
	else if(strcmp(argv[1], "-o") == 0){
		
		mont1.flagPreProcess = 1;
	}
	else {
		printf("Diretiva nao encontrada\n");
		return 0;
	}
	mont1.NomeTextoFinal = nomeArquivoFinal + ".txt";
	EscreveArquivoPreProcessado(argv[2], mont1);
	if( mont1.PrimeiraPassagem() != 0 )
		return 0;
	mont1.SegundaPassagem();
	rename("preprocess.txt", nomeArquivoPre.c_str());
	
	return 0;
}
