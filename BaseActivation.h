#ifndef BASEACTIVATION_H
#define BASEACTIVATION_H

#include <string>
#include <vector>

using namespace std;

class BaseActivation {
    private:
        string name;
    public:
        BaseActivation();
        virtual double activate(double val) {};
        virtual vector<double> activate(vector<double> vals) {};
        virtual double calcualte_gradient(double val) {};
        virtual vector<double> calcualte_gradient(vector<double> vals) {};
        string get_name();
        ~BaseActivation();
};

#endif