#ifndef CONNECTION_H
#define CONNECTION_H

#include "Neuron.h"

class Connection {
    private: 
        Neuron *head;
        Neuron *tail;
        double weight;

    public:
        Connection(Neuron *head, Neuron *tail, double weight);
        Neuron *get_head();
        void set_head(Neuron *head);
        Neuron *get_tail();
        void set_tail(Neuron *tail);
        double get_weight();
        void set_weight(double weight);
};


#endif