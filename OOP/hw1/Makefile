main.out: main.o matrix33.o vector3.o
	
	g++-6 -o main.out main.o  vector3.o matrix33.o

main.o: main.cpp vector3.h matrix33.h
	g++-6 -c main.cpp

vector3.o: vector3.cpp vector3.h
	g++-6 -c vector3.cpp

matrix33.o: matrix33.cpp matrix33.h
	g++-6 -c matrix33.cpp

clean:
	rm -f *.o
