#include "Network.h"
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv) {

    vector<int> hidden_layers_sizes = {2, 1, 3};

    Network *network = new Network(3, hidden_layers_sizes, 3);

    cout << "------input layer------" << endl;
    for (auto neuron : network->get_input_layer()->get_neurons()) {
        cout << "neuron: " << neuron << endl;
    } 

    int i = 0;
    for (auto layer : network->get_connections()) {
        if (i == 0) 
            cout << "------input to hidden 1 connections------" << endl;
        else if (i < network->get_hidden_layers().size() - 1)
            cout << "------hidden " << i << " to hidden " << (i+1) << "connections------" << endl;
        else 
            cout << "------hidden " << i << " to output connections------" << endl;
        for (auto connection : layer) {
            cout << "head: " << connection->get_head() << " ";
            cout << "tail: " << connection->get_tail() << endl;
        }
        i++;
    }

    cout << "------output layer------" << endl;
    for (auto neuron : network->get_output_layer()->get_neurons()) {
        cout << "neuron: " << neuron << endl;
    } 

    vector<double> sample = {1, 2, 3};
    vector<double> output = network->forward_pass(sample);

    for(double val : output) {
        cout << val << " ";
    }
    cout << endl;

    vector<double> expected_output = {0, 1, 0};
    double loss = network->calculate_loss(expected_output);

    vector<double> loss_derivatives = network->loss_derivative(expected_output);
    for (double d : loss_derivatives) {
        cout << d << " ";
    }
    cout << endl;

    cout << "loss: " << loss << endl;
    
    return 0;
}