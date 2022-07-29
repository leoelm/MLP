#include "Layer.h"
#include <iostream>

using namespace std;

int main() {

    Layer *layer = new Layer(10);

    cout << layer->get_size() << endl;

    return 0;
}