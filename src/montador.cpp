#include "montador.hpp"

montador::montador() {
    setPC(0);
    setACC(0);

    // adicao da tabela de instrucoes
    //  No formato instrucao, opcode
    Tabela_de_Instrucoes.insert ( pair<string,int>("ADD", 1) );
    Tabela_de_Instrucoes.insert ( pair<string,int>("SUB", 2) );
    Tabela_de_Instrucoes.insert ( pair<string,int>("MULT", 3) );
    Tabela_de_Instrucoes.insert ( pair<string,int>("DIV", 4) );
    Tabela_de_Instrucoes.insert ( pair<string,int>("JMP", 5) );
    Tabela_de_Instrucoes.insert ( pair<string,int>("JMPN", 6) );
    Tabela_de_Instrucoes.insert ( pair<string,int>("JMPP", 7) );
    Tabela_de_Instrucoes.insert ( pair<string,int>("JMPZ", 8) );
    Tabela_de_Instrucoes.insert ( pair<string,int>("COPY", 9) );
    Tabela_de_Instrucoes.insert ( pair<string,int>("LOAD", 10) );
    Tabela_de_Instrucoes.insert ( pair<string,int>("STORE", 11) );
    Tabela_de_Instrucoes.insert ( pair<string,int>("INPUT", 12) );
    Tabela_de_Instrucoes.insert ( pair<string,int>("OUTPUT", 13) );
    Tabela_de_Instrucoes.insert ( pair<string,int>("STOP", 14) );

    // tabela de Diretivas
    Tabela_de_Diretivas.insert ( pair<string,int>("SECTION", 1) );
    Tabela_de_Diretivas.insert ( pair<string,int>("SPACE", 2) );
    Tabela_de_Diretivas.insert ( pair<string,int>("CONST", 3) );
    Tabela_de_Diretivas.insert ( pair<string,int>("EQU", 4) );
    Tabela_de_Diretivas.insert ( pair<string,int>("IF", 5) );
}

montador::~montador() {

}

// metodos get

map<string, int> montador::getTabela_de_Instrucoes() {
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
        cout << "element 'z' already existed";
        cout << " with a value of " << ret.first->second << '\n';
        return -1;
    }
    return 1;
}

int montador::checkIfInstruction(string str) {
    /* verifica se uma string faz parte da tabela de instrucoes,
     * caso faca, retorna seu opcode, se nao retorna 0
     */
    map<string,int>::iterator it;
    it = Tabela_de_Instrucoes.find(str);
    if (it != Tabela_de_Instrucoes.end())
        return Tabela_de_Instrucoes.find(str)->second;
    return 0;
    
}