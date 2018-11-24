#ifndef __Node_H_INCLUDED__
#define __Node_H_INCLUDED__

#include <vector>
#include <iostream>

class Node {
  private:
    std::vector<double> weights;
    std::vector<double> pastWeights;
    double value = 0;
    double preSigmoidValue = 0;
  public:
    Node(std::vector<double> w);
    std::vector<double> getWeights();
    std::vector<double> getPastWeights();
    void setValue(double nodeValue);
    double getValue();
    void setPreSigmoidValue(double sigValue);
    double getPreSigmoidValue();
    void setWeights(std::vector<double> weight);
};

#endif
