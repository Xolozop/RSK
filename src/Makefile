all: main.o classical.o
	g++ main.o classical.o -o rsk

main.o: main.cpp classical.h types.h
	g++ -c main.cpp

classical.o: classical.cpp classical.h types.h
	g++ -c classical.cpp

clean:
	rm -f ./*.o rsk

