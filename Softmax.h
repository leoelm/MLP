#ifndef SOFTMAX_H
#define SOFTMAX_H

#include "BaseActivation.h"
#include <vector>

using namespace std;

class Softmax : public BaseActivation {
    private:
        string name = "Softmax";
    public:
        vector<double> activate(vector<double> vals);
};

#endif