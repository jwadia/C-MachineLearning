#ifndef __NuralNetwork_H_INCLUDED__
#define __NuralNetwork_H_INCLUDED__

#include <vector>
#include <iostream>
#include <ctime>
#include "../util/Node.h"
#include "../util/Functions.h"

class NuralNetwork {
  private:
    std::vector<std::vector<Node>> network;
  public:
    NuralNetwork(std::vector<int> layers);
    std::vector<double> predict(std::vector<double> inputs);
};

#endif
