prog: *.o
	g++ -std=c++11 *.o -o prog
main.o: main.cpp
	g++ -std=c++11 -c main.cpp -o main.o
Neuron.o: Neuron.cpp Neuron.h
	g++ -std=c++11 -c Neuron.cpp -o Neuron.o
clean:
	rm prog *.o