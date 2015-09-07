capsh :  main.o  findfile.o
	cc -o capsh main.o findfile.o
main.o : main.c findfile.h
	cc -c main.c 
findfile.o : findfile.c findfile.h
	cc -c findfile.c
clean : rm capsh main.o findfile.o
