#include "Node.h"

Node::Node(std::vector<double> w) {
  for(double i: w) {
    weights.push_back(i);
  }
}

std::vector<double> Node::getWeights(){
  return weights;
}

void Node::setValue(double nodeValue) {
  value = nodeValue;
}

double Node::getValue() {
  return value;
}
