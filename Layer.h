#ifndef LAYER_H
#define LAYER_H

#include <vector>
#include "Connection.h"
#include "BaseActivation.h"

using namespace std;

#define INITIAL_WEIGHT 1

class Layer {
    private: 
        int size;
        vector<Neuron*> neurons;
        BaseActivation *activation_function;
    public:
        Layer(int size);
        Layer(int size, BaseActivation *activation_function);
        int get_size();
        vector<Connection*> create_connections_to_layer(Layer *target_layer);
        vector<Neuron*> get_neurons();
        Neuron *get_single_neuron(int pos);
        void set_single_neuron(int pos, Neuron *neuron);
        BaseActivation *get_activation_function();
        void set_activation_function(BaseActivation *activation_function);
        void add_neuron(Neuron *neuron);
        void remove_neuron(int pos);
};

#endif