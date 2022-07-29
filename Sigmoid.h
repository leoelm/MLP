#ifndef SIGMOID_H
#define SIGMOID_H

#include "BaseActivation.h"

class Sigmoid : public BaseActivation {
    private:
        string name = "Sigmoid";
    public:
        double activate(double val);
        double calculate_gradient(double val);
};

#endif