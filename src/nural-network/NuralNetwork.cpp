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
      network[i][j].setPreSigmoidValue(sum);
      network[i][j].setValue(func.sigmoid(sum));
    }
  }
  std::vector<double> output = {};
  for(Node i:network[network.size()-1]) {
    output.push_back(i.getValue());
  }
  return output;
}

void NuralNetwork::backpropogation(std::vector<double> inputs, std::vector<double> output) {
  std::vector<double> outputSumMarginError = {};
  std::vector<double> deltaOutputSum = {};
  std::vector<std::vector<double>> deltaWeights = {};
  std::vector<std::vector<double>> tempWeights = {};
  std::vector<double> calculated = predict(inputs);
  int count = 0;
  Functions f;
  for(int i = 0; i < calculated.size(); i++) {
    outputSumMarginError.push_back(output[i]-calculated[i]);
  }
  for(int i = 0; i < network[network.size()-1].size(); i++) {
    deltaOutputSum.push_back(f.dsigmoid(network[network.size()-1][i].getPreSigmoidValue())*outputSumMarginError[i]);
  }
  for(int i = 0; i < network[network.size()-2].size(); i++) {
    tempWeights.push_back({});
    for(int j = 0; j < network[network.size()-2][i].getWeights().size(); j++) {
      tempWeights[i].push_back(network[network.size()-2][i].getWeights()[j]);
    }
  }
  for(Node j:network[network.size()-2]) {
    deltaWeights.push_back({});
    for(double i:deltaOutputSum) {
      deltaWeights[count].push_back(i*j.getValue());
    }
    count++;
  }
  count = 0;
  for(int i = 0; i < network[network.size()-2].size(); i++) {
    for(int j = 0; j < network[network.size()-1].size(); j++) {
      tempWeights[i][j]=tempWeights[i][j]+deltaWeights[i][j];
      std::cout<<tempWeights[i][j]<<" ";
    }
    std::cout<<std::endl;
  }
  std::cout<<network[network.size()-2][0].getWeights()[0]<<std::endl;
  for(Node i:network[network.size()-2]) {
    i.setWeights(tempWeights[count]);
    count++;
  }
  count = 0;
  std::cout<<network[network.size()-2][0].getPastWeights()[0]<<std::endl;
}
