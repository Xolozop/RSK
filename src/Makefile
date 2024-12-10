all: main.o classical.o geometrical.o slow_classical.o
	g++ main.o classical.o geometrical.o slow_classical.o -o rsk

main.o: main.cpp classical.h types.h
	g++ -c main.cpp

slow_classical.o: slow_classical.cpp slow_classical.h types.h
	g++ -c slow_classical.cpp

classical.o: classical.cpp classical.h types.h
	g++ -c classical.cpp

geometrical.o: geometrical.cpp geometrical.h types.h
	g++ -c geometrical.cpp

clean:
	rm -f ./*.o rsk

