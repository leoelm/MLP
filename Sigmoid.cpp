#include "Sigmoid.h"
#include "math.h"

using namespace std;

double Sigmoid::activate(double val) {
    double denominator = 1 + exp(-val);

    return 1/denominator;
}

double Sigmoid::calculate_gradient(double val) {
    double q = this->activate(val);

    return q*(1-q);
}