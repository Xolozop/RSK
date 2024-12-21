all: main.o classical.o geometrical.o withlocalrulesRSK.o
	g++ main.o classical.o geometrical.o withlocalrulesRSK.o -o rsk

main.o: main.cpp classical.h types.h
	g++ -c main.cpp

classical.o: classical.cpp classical.h types.h
	g++ -c classical.cpp

geometrical.o: geometrical.cpp geometrical.h types.h
	g++ -c geometrical.cpp

withlocalrulesRSK.o: withlocalrulesRSK.cpp withlocalrulesRSK.h types.h
	g++ -c withlocalrulesRSK.cpp

clean:
	rm -f ./*.o rsk

