#include "Connection.h"

Connection::Connection(Neuron *head, Neuron *tail, double weight) {
    this->head = head;
    this->tail = tail;
    this->weight = weight;
}

Neuron *Connection::get_head() {
    return this->head;
}

void Connection::set_head(Neuron *head) {
    this->head = head;
}

Neuron *Connection::get_tail() {
    return this->tail;
}

void Connection::set_tail(Neuron *tail){
    this->tail = tail;
}

double Connection::get_weight() {
    return this->weight;
}

void Connection::set_weight(double weight) {
    this->weight = weight;
}