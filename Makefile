prog: *.o
	g++ -std=c++11 *.o -o prog
Layer.o: Layer.cpp Layer.h Connection.o BaseActivation.o
	g++ -std=c++11 -c Layer.cpp -o Layer.o
Connection.o: Connection.cpp Connection.h Neuron.o BaseActivation.o
	g++ -std=c++11 -c Connection.cpp -o Connection.o
Neuron.o: Neuron.cpp Neuron.h
	g++ -std=c++11 -c Neuron.cpp -o Neuron.o
BaseActivation.o: BaseActivation.cpp BaseActivation.h
	g++ -std=c++11 -c BaseActivation.cpp -o BaseActivation.o
main.o: main.cpp Layer.o
	g++ -std=c++11 -c main.cpp -o main.o
clean:
	rm prog *.o