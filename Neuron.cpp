#include "Neuron.h"

Neuron::Neuron(double val) {
    this->val = val;
}

double Neuron::get_value() {
    return this->val;
}

void Neuron::set_value(double val) {
    this->val = val;
}

void Neuron::add_value(double val) {
    this->val += val;
}