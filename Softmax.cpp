#include "Softmax.h"
#include "math.h"

using namespace std;

vector<double> Softmax::activate(vector<double> vals) {
    double denominator = 0;
    vector<double> out;
    for (double val : vals) {
        denominator += exp(val);
    }

    for (double val : vals) {
        out.push_back(exp(val)/denominator);
    }

    return out;
}