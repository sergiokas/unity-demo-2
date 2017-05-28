all: compile
	./test

compile:
	gcc -c -Wall -o unity.o unity/unity.c
	gcc -c -Wall -o examen.o examen.c
	gcc -c -Wall -o test.o test.c
	gcc -o test test.o examen.o unity.o 

clean: 
	rm -f *.o test
