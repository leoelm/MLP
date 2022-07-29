prog: *.o
	g++ -std=c++11 *.o -o prog
main.o: main.cpp
	g++ -std=c++11 -c main.cpp -o main.o
Connection.o: Connection.cpp Connection.h
	g++ -std=c++11 -c Connection.cpp -o Connection.o
Neuron.o: Neuron.cpp Neuron.h
	g++ -std=c++11 -c Neuron.cpp -o Neuron.o
BaseActivation.o: BaseActivation.cpp BaseActivation.h
	g++ -std=c++11 -c BaseActivation.cpp -o BaseActivation.o
clean:
	rm prog *.o