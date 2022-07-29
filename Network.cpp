#include "Network.h"
#include <vector>
#include <math.h>
#include "Sigmoid.h"
#include "Softmax.h"

using namespace std;

Network::Network(int input_size, vector<int> hidden_layer_sizes, int output_size) {
    this->input_layer = new Layer(input_size);
    this->output_layer = new Layer(output_size, new Softmax());
    this->hidden_layers = vector<Layer*>();

    int num_hidden_layers = hidden_layer_sizes.size();

    for (int i = 0; i < num_hidden_layers; i++) {
        this->hidden_layers.push_back(new Layer(hidden_layer_sizes[i], new Sigmoid()));
    }

    for (int i = 0; i < num_hidden_layers; i++) {
        if (i == 0) 
            this->connections.push_back(this->input_layer->create_connections_to_layer(this->hidden_layers[i]));
        if (i+1 == num_hidden_layers) 
            this->connections.push_back(this->hidden_layers[i]->create_connections_to_layer(this->output_layer));
        else {
            this->connections.push_back(this->hidden_layers[i]->create_connections_to_layer(this->hidden_layers[i+1]));
        }
    }
}

Layer* Network::get_input_layer() {
    return this->input_layer;
}

Layer* Network::get_output_layer() {
    return this->output_layer;
}

vector<Layer*> Network::get_hidden_layers() {
    return this->hidden_layers;
}

vector<vector<Connection*>> Network::get_connections() {
    return this->connections;
}

vector<double> Network::forward_pass(vector<double> input) {
    vector<Neuron *> input_layer_neurons = this->input_layer->get_neurons();
    for (int i = 0; i < this->input_layer->get_size(); i++) {
        Neuron *neuron = input_layer_neurons[i];
        double input_value = input[i];

        neuron->set_value(input_value);
    }
    int k = 0;
    for (auto layer_connections : connections) {
        for (Connection* connection : layer_connections) {
            Neuron *head = connection->get_head();
            Neuron *tail = connection->get_tail();

            //update tail value i.e. add weighted head value
            tail->add_value(head->get_value()*connection->get_weight());
        }

        if (k < this->hidden_layers.size()) { //activate values in hidden layer before updating next hidden layer values
            Layer *layer = this->hidden_layers[k]; 

            for (Neuron *neuron : layer->get_neurons()) {
                neuron->set_value(layer->get_activation_function()->activate(neuron->get_value()));
            }
        }

        k++;
    }

    vector<double> output_values;
    for (Neuron *neuron : this->output_layer->get_neurons()) {
        output_values.push_back(neuron->get_value());
    }

    vector<double> activated_output_values = this->output_layer->get_activation_function()->activate(output_values);

    return activated_output_values;
}

double Network::calculate_loss(vector<double> expected_output) {

    //Multi-class cross entropy loss

    vector<double> output;

    for (Neuron *neuron : this->output_layer->get_neurons()) {
        output.push_back(neuron->get_value());
    }

    double loss = 0;
    for (int i = 0; i < this->output_layer->get_neurons().size(); i++) {
        double actual = output[i];
        double expected = expected_output[i];

        loss -= expected*log(actual);
    }

    return loss;
}

vector<double> Network::loss_derivative(vector<double> expected_output) {
    vector<double> loss_ds;
    vector<double> predictions;
    for (Neuron *neuron : this->output_layer->get_neurons()) {
        predictions.push_back(neuron->get_value());
    }

    for (int i = 0; i < this->output_layer->get_neurons().size(); i++) {
        double prediction = predictions[i];
        double expected = expected_output[i];

        loss_ds.push_back(prediction - expected);
    }

    return loss_ds;
}