#ifndef NETWORK_H
#define NETWORK_H

#include "Layer.h"
#include <vector>

using namespace std;

class Network {
    private:
        Layer *input_layer;
        Layer *output_layer;
        vector<Layer*> hidden_layers;
        vector<vector<Connection*>> connections;
    public:
        Network(int input_size, vector<int> hidden_layer_sizes, int output_size);
        Layer *get_input_layer();
        Layer *get_output_layer();
        vector<Layer*> get_hidden_layers();
        vector<vector<Connection*>> get_connections();
        vector<double> forward_pass(vector<double> input);
        double calculate_loss(vector<double>expected_output);
        vector<double> loss_derivative(vector<double> expected_output);
};

#endif