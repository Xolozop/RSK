all: main.o classical.o geometrical.o
	g++ main.o classical.o geometrical.o -o rsk

main.o: main.cpp classical.h types.h
	g++ -c main.cpp

classical.o: classical.cpp classical.h types.h
	g++ -c classical.cpp

geometrical.o: geometrical.cpp geometrical.h types.h
	g++ -c geometrical.cpp

clean:
	rm -f ./*.o rsk

