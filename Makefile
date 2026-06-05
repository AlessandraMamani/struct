test: main.o structs.o
	gcc main.o structs.o -o test

main.o: main.c structs.h
	gcc -c -g main.c

structs.o: structs.c structs.h ritchie.h
	gcc -c -g structs.c

clean:
	rm -f *.o test

