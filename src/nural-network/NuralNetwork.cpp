#include "NuralNetwork.h"

NuralNetwork::NuralNetwork(std::vector<int> layers) {
  srand(time(0));
  for(int i = 0; i < layers.size(); i++) {
    network.push_back({});
    for(int j = 0; j < layers[i]; j++) {
      std::vector<double> randWeights = {};
      if(i != layers.size()-1) {
        for(int k = 0; k < layers[i+1]; k++) {
          randWeights.push_back((double)(rand()%100)/100);
        }
      }
      network[i].push_back(Node(randWeights));
    }
  }
}

std::vector<double> NuralNetwork::predict(std::vector<double> inputs) {
  double sum = 0;
  Functions func;
  for(int i = 0; i < inputs.size(); i++) {
    network[0][i].setValue(inputs[i]);
  }
  for(int i = 1; i < network.size(); i++) {
    for(int j = 0; j < network[i].size(); j++) {
      sum = 0;
      for(int k = 0; k < network[i-1].size(); k++) {
        sum+=network[i-1][k].getWeights()[j]*network[i-1][k].getValue();
      }
      network[i][j].setValue(func.sigmoid(sum));
    }
  }
  std::vector<double> output = {};
  for(Node i:network[network.size()-1]) {
    output.push_back(i.getValue());
  }
  return output;
}
