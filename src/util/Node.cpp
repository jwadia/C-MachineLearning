#include "Node.h"

Node::Node(std::vector<double> w) {
  for(double i: w) {
    weights.push_back(i);
  }
}

void Node::setWeights(std::vector<double> weight){
  pastWeights = weights;
  //std::cout<<pastWeights[0]<<std::endl;
  weights = weight;
}

std::vector<double> Node::getWeights(){
  return weights;
}

std::vector<double> Node::getPastWeights(){
  std::cout<<pastWeights[0]<<std::endl;
  return pastWeights;
}

void Node::setValue(double nodeValue) {
  value = nodeValue;
}

double Node::getValue() {
  return value;
}

void Node::setPreSigmoidValue(double sigValue) {
  preSigmoidValue = sigValue;
}

double Node::getPreSigmoidValue() {
  return preSigmoidValue;
}
