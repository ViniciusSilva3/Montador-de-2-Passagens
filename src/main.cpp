#include <bits/stdc++.h>
#include "leitordearquivos.hpp"
#include "montador.hpp"

int main(int argc, char* argv[]) {
	montador mont1;
	int teste;
	printf("%d %d", mont1.getPC(), mont1.getACC());
	mont1.insertNewSymbol("asd", 10);
	mont1.insertNewSymbol("asd", 6);
	teste = mont1.checkIfInstruction("ADD");
	cout << teste << endl;
	teste = mont1.checkIfInstruction("teste");
	cout << teste << endl;
	return 0;
}
