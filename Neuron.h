#ifndef NEURON_H
#define NEURON_H

class Neuron {
    private:
        double val;

    public:
        Neuron(double val);
        double get_value();
        void set_value(double val);
        void add_value(double val);
};

#endif