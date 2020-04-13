all: solve

alternative: 
		g++ figure.cpp game.cpp main.cpp -o main

solve: figure.o game.o main.o
		g++ main.o game.o figure.o -o main

main.o: main.cpp
		g++ -c main.cpp

game.o: game.cpp
		g++ -c game.cpp

figure.o: figure.cpp
		g++ -c figure.cpp

clean:
	del -rf *.o *.exe
