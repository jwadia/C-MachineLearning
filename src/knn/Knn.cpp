#include "Knn.h"

KNN::KNN(std::vector<double> xList, std::vector<double> yList, std::vector<double> lList, int num) {
  x = xList;
  y = yList;
  k = num;
  label = lList;
}

double KNN::predict(double px, double py) {
  std::vector<std::vector<double>> distance;
  std::vector<double> temp;
  std::vector<std::vector<double>> count;
  int status = true;

  for(int i = 0; i < x.size(); i++) {
    distance.push_back({sqrt(pow((x[i])-px, 2)+pow((y[i])-py, 2))});
    distance[i].push_back(label[i]);
  }

  do {
    status = true;
    for(int i = 0; i < distance.size()-1; i++) {
      if(distance[i][0] > distance[i+1][0]) {
        temp = distance[i];
        distance[i] = distance[i+1];
        distance[i+1] = temp;
        temp.clear();
      }
    }
    for(int i = 0; i < distance.size()-1; i++) {
      if(distance[i][0] > distance[i+1][0]) {
        status = false;
      }
    }
  } while(!status);

  status = false;

  for(int i = 0; i < k; i++) {
    for(int j = 0; j < count.size(); j++) {
      if(distance[i][1] == count[j][1]) {
        count[j][2]+=1;
        status = true;
      }
    }
    if(!status) {
      distance[i].push_back(1);
      count.push_back(distance[i]);
    }
    status = false;
  }
  temp = {0,0,0};
  for(std::vector<double> v : count) {
    if(temp[2] < v[2]) {
      temp = v;
    }
  }
  return temp[1];
}
