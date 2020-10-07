section text
COPY           ZERO, OLDER
COPY           ONE, OLD
INPUT          LIMIT
OUTPUT         OLD
FRONT:  LOAD           OLDER
ADD            OLD
STORE          NEW
SUB            LIMIT
JMPP           FINAL
OUTPUT         NEW
COPY           OLD,OLDER
COPY           NEW,OLD
JMP            FRONT
FINAL:  OUTPUT         LIMIT
STOP
section data
ZERO:   CONST          -11
ONE:    CONST          -2
OLDER:  SPACE
OLD:    SPACE
NEW:    SPACE
LIMIT:  SPACE