#include "montador.hpp"
#include "leitordearquivos.hpp"

montador::montador() {
    setPC(0);
    setACC(0);

    // adicao da tabela de instrucoes
    //  No formato instrucao, opcode
    Tabela_de_Instrucoes.insert ( pair<string,pair<int, int>>("ADD", make_pair(1, 2) ));
    Tabela_de_Instrucoes.insert ( pair<string,pair<int, int>>("SUB", make_pair(2, 2)) );
    Tabela_de_Instrucoes.insert ( pair<string,pair<int, int>>("MULT", make_pair(3, 2)) );
    Tabela_de_Instrucoes.insert ( pair<string,pair<int, int>>("DIV", make_pair(4, 2)) );
    Tabela_de_Instrucoes.insert ( pair<string,pair<int, int>>("JMP", make_pair(5, 2)) );
    Tabela_de_Instrucoes.insert ( pair<string,pair<int, int>>("JMPN", make_pair(6, 2)) );
    Tabela_de_Instrucoes.insert ( pair<string,pair<int, int>>("JMPP", make_pair(7, 2)) );
    Tabela_de_Instrucoes.insert ( pair<string,pair<int, int>>("JMPZ", make_pair(8, 2)) );
    Tabela_de_Instrucoes.insert ( pair<string,pair<int, int>>("COPY", make_pair(9, 3)) );
    Tabela_de_Instrucoes.insert ( pair<string,pair<int, int>>("LOAD", make_pair(10, 2)) );
    Tabela_de_Instrucoes.insert ( pair<string,pair<int, int>>("STORE", make_pair(11, 2)) );
    Tabela_de_Instrucoes.insert ( pair<string,pair<int, int>>("INPUT", make_pair(12, 2)) );
    Tabela_de_Instrucoes.insert ( pair<string,pair<int, int>>("OUTPUT", make_pair(13, 2)) );
    Tabela_de_Instrucoes.insert ( pair<string,pair<int, int>>("STOP", make_pair(14, 1)) );

    // tabela de Diretivas
    Tabela_de_Diretivas.insert ( pair<string,int>("SECTION", 2) );
    Tabela_de_Diretivas.insert ( pair<string,int>("SPACE", 1) );
    Tabela_de_Diretivas.insert ( pair<string,int>("CONST", 1) );
    Tabela_de_Diretivas.insert ( pair<string,int>("EQU", 1) );
    Tabela_de_Diretivas.insert ( pair<string,int>("IF", 1) );
}

montador::~montador() {

}

// metodos get

map<string, pair<int, int>> montador::getTabela_de_Instrucoes() {
    return Tabela_de_Instrucoes;
}

map<string, int> montador::getTabela_de_Simbolos() {
    return Tabela_de_Simbolos;
}

map<string, int> montador::getTabela_de_Diretivas() {
    return Tabela_de_Diretivas;
}

int montador::getPC() {
    return PC;
}

int montador::getACC() {
    return ACC;
}

// metodos set

void montador::setPC(int x) {
    PC = x;
}

void montador::setACC(int x) {
    ACC = x;
}

// outros metodos

int montador::insertNewSymbol(string str, int x) {
    /* if successfull return 1, else return -1 */
    pair<string, int> temp(str, x);
    pair<map<string,int>::iterator,bool> ret;
    ret = Tabela_de_Simbolos.insert(temp);
    if (ret.second==false) {
        return -1;
    }
    return 1;
}

pair<int, int> montador::checkIfInstruction(string str) {
    /* verifica se uma string faz parte da tabela de instrucoes,
     * caso faca, retorna seu opcode, se nao retorna 0
     */
    map<string,pair<int, int>>::iterator it;
    it = Tabela_de_Instrucoes.find(str);
    if (it != Tabela_de_Instrucoes.end())
        return Tabela_de_Instrucoes.find(str)->second;
    return make_pair(0, 0);
    
}

 int montador::checkIfDiretiva(string str) {
    /* verifica se uma string faz parte da tabela de instrucoes,
     * caso faca, retorna seu opcode, se nao retorna 0
     */
    map<string, int>::iterator it;
    it = Tabela_de_Diretivas.find(str);
    if (it != Tabela_de_Diretivas.end())
        return Tabela_de_Diretivas.find(str)->second;
    return 0;
    
}

int montador::checkIfRotulo(string str) {
    int check;
	/* caso o primeiro elemento seja um simbolo */
	if(str.back() == ':')
        return 1;
    return 0;
}

int montador::PrimeiraPassagem() {
    int contador_linha, contador_palavras, verificaRotulo, insereTabelaSimbolo, verificador2;
    pair<int, int> verificador;
    contador_linha = 1;
    contador_palavras = 0;
    string linha;
    vector<string> tokens;
    ifstream MyFile("preprocess.txt");
    while(getline(MyFile, linha)) {
        if ( !tokens.empty() ) {
			tokens.clear();
		}
        tokens = split(linha);
        

        verificaRotulo = checkIfRotulo(tokens[0]); // verifica se primeiro token da linha em um rotulo
        if(verificaRotulo==1) {
            insereTabelaSimbolo = insertNewSymbol(tokens[0], contador_palavras);
                if( insereTabelaSimbolo == -1 ) {
                    cout << "INSERCAO INVALIDA -> ERRO" << endl;
                }
                else {
                    verificador = checkIfInstruction(tokens[1]); // verifica elemento seguinte ao rotulo
                    if( verificador.first == 0 ) {
                        /* NAO eh uma instrucao, verifica se eh uma diretiva */
                        verificador2 = checkIfDiretiva(tokens[1]);
                        if( verificador2 == 0 ) {
                            /* Caso em que nao eh nem diretiva nem instrucao */
                            cout << "ERRO -> NAO EH ROTULO NEM DIRETIVA" << endl;
                            }
                        else {
                            /* Caso em que eh uma diretiva */
                            contador_palavras += verificador2;
                        }
                    }
                    else {
                        /* caso em que eh uma instrucao */
                        contador_palavras += verificador.second;
                    }
                }
        }
        else {
            /* CASO EM QUE PRIMEIRO ELEMENTO DA LINHA NAO EH UM ROTULO */
            verificador = checkIfInstruction(tokens[0]); // verifica elemento seguinte ao rotulo
                    if( verificador.first == 0 ) {
                        /* NAO eh uma instrucao, verifica se eh uma diretiva */
                        verificador2 = checkIfDiretiva(tokens[0]);
                        if( verificador2 == 0 ) {
                            /* Caso em que nao eh nem diretiva nem instrucao */
                            cout << "ERRO -> NAO EH ROTULO NEM DIRETIVA" << endl;
                            }
                        else {
                            /* Caso em que eh uma diretiva */
                            contador_palavras += verificador2;
                        }
                    }
                    else {
                        /* caso em que eh uma instrucao */
                        contador_palavras += verificador.second;
                    }
        }
    }
    // verificar valores
    map<string, int> ts;
    ts = getTabela_de_Simbolos();
    for(auto it = ts.cbegin(); it != ts.cend(); ++it)
    {
        cout << it->first << " " << it->second << "\n";
    }
    MyFile.close();
    return 0;
}