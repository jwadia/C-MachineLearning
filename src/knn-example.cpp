#include <vector>
#include <iostream>
#include "knn/Knn.h"

int main() {
  std::vector<double> x = {1,2,0,0,2};
  std::vector<double> y = {1,2,2,0,0};
  std::vector<double> label = {1,1,1,0,0};
  int n = 3;

  KNN k(x,y,label,n);
  std::cout<<k.predict(1,0);

  return 0;
}
