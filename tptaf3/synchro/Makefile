CC=gcc
CFLAGS=-g -Wall 
LFLAGS=-lm -lpthread
T=100000

V1: 	systeme.c
	${CC} ${CFLAGS} systeme.c ${LFLAGS} -o sv1 
VT1: 	systeme.c
	${CC} ${CFLAGS} -DTEMPO=${T} systeme.c ${LFLAGS} -o sv1tempo
VSYNCH: systeme_synch.c
	${CC} ${CFLAGS} -DTEMPO=${T} systeme_synch.c ${LFLAGS} -o svsynch
VCORRIGE: corrige.c
	${CC} ${CFLAGS} -DTEMPO=${T} corrige.c ${LFLAGS} -o svcorrige

clean:
	rm *~ *.o sv*
