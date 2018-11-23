#ifndef __Node_H_INCLUDED__
#define __Node_H_INCLUDED__

#include <vector>
#include <iostream>

class Node {
  private:
    std::vector<double> weights;
    double value = 0;
  public:
    Node(std::vector<double> w);
    std::vector<double> getWeights();
    void setValue(double nodeValue);
    double getValue();
};

#endif
