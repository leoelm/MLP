#include "layer.h"
#include <stdexcept>

using namespace std;

Layer::Layer(int size) {
    this->size = size;
    this->neurons = vector<Neuron *>();
    for (int i = 0; i < this->size; i++) {
        this->neurons.push_back(new Neuron(0.0));
    }
}

Layer::Layer(int size, BaseActivation *activation_function) {
    this->size = size;
    this->activation_function = activation_function;
    this->neurons = vector<Neuron *>();
    for (int i = 0; i < this->size; i++) {
        this->neurons.push_back(new Neuron(0.0));
    }
}

int Layer::get_size() {
    return this->size;
}

vector<Connection*> Layer::create_connections_to_layer(Layer *target_layer) {
    vector<Connection*> connections;
    for (auto head : this->neurons) {
        for (auto tail : target_layer->get_neurons()) {
            Connection* con = new Connection(head, tail, INITIAL_WEIGHT);
            connections.push_back(con);
        }
    }

    return connections;
}

vector<Neuron *> Layer::get_neurons() {
    return this->neurons;
}

Neuron* Layer::get_single_neuron(int pos) {
    if (0 <= pos < this->size) 
        return this->neurons[pos];
    else
        throw std::invalid_argument("The position is out of bounds.");
}

void Layer::set_single_neuron(int pos, Neuron *neuron) {
    if (0 <= pos < this->size) {
        this->neurons[pos] = neuron;
    } else {
        throw std::invalid_argument("The position is out of bounds.");
    }
}

BaseActivation* Layer::get_activation_function() {
    return this->activation_function;
}

void Layer::set_activation_function(BaseActivation *activation_function) {
    this->activation_function = activation_function;
}

void Layer::add_neuron(Neuron *neuron) {
    this->size++;
    this->neurons.push_back(neuron);
}

void Layer::remove_neuron(int pos) {
    if (0 <= pos < this->size) {
        this->neurons.erase(std::next(this->neurons.begin(), pos));
    } else {
        throw std::invalid_argument("The position is out of bounds.");
    }
}