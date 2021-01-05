TpLangageFormel: main.o ensemble.o pile.o afn.o
	gcc -W -Wall main.o ensemble.o pile.o afn.o -o TpLangageFormel

main.o: main.c ensemble.h pile.h
	gcc -W -Wall -c main.c -o main.o

ensemble.o: ensemble.c ensemble.h
	gcc -W -Wall -c ensemble.c -o ensemble.o

pile.o: pile.c pile.h
	gcc -W -Wall -c pile.c -o pile.o

afn.o: afn.c ensemble.h afn.h
	gcc -W -Wall -c afn.c -o afn.o

clean:
	rm -f TpLangageFormel *.o
