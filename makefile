all: main.o construction.o 
	gcc -o main main.o construction.o
main.o: main.c construction.h
	gcc -c main.c
construction.o: construction.c construction.h
	gcc -c construction.c
run:
	./main
clean:
	rm *.o
	rm main
