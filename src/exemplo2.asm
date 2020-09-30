SECTION TEXT ;tem que remover esse comentario
INPUT         N ;esse tambem
LOAD N
FAT: 

  SUB ONE
COPY N1         M2
JMPZ FIM
STORE AUX ; e esse
LABEL:
  ;oi
  
  loAD AUX
JMP Fat
Fim: 

;asdiasiod
OUTPUT N ; mais esse aqui
Stop
SECTION DATA
AUX: SPACE
N: SPACE
ONE: CONST 1
