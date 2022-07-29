#include "Connection.h"
#include <iostream>

using namespace std;

int main() {

    Neuron* n1 = new Neuron(0); 
    Neuron* n2 = new Neuron(0);

    Connection* connection = new Connection(n1, n2, 1);

    cout << connection->get_weight() << endl;

    return 0;
}