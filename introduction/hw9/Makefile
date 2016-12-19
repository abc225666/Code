main: main.o recognizer.o generator.o
	gcc-6 -o main.out main.o recognizer.o generator.o
main.o: main.c recognizer.h
	gcc-6 -c main.c
recognizer.o: recognizer.h recognizer.c
	gcc-6 -c recognizer.c
generator.o: generator.h generator.c
	gcc-6 -c generator.c