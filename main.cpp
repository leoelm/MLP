#include "Neuron.h"
#include <iostream>

using namespace std;

int main() {

    Neuron* neuron = new Neuron(0); 

    cout << neuron->get_value() << endl;

    return 0;
}