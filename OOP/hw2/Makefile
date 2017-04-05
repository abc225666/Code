main.out : main.o 0516062_Link_List.o
	g++-6 -o main.out main.o 0516062_Link_List.o

main.o: main.cpp 0516062_Link_List.h
	g++-6 -c main.cpp

0516062_Link_List.o: 0516062_Link_List.cpp 0516062_Link_List.h
	g++-6 -c 0516062_Link_List.cpp

clean:
	rm *.o
