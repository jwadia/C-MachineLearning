#include <vector>
#include <iostream>
#include "regression/Regression.h"

int main() {
  std::vector<double> x = {-3,-2,-1,-0.2,1,3};
  std::vector<double> y = {0.9,0.8,0.4,0.2,0.1,0};

  Regression r(x,y);
  std::vector<double> v = r.PolynomialRegression(4);

  for(double d : v) {
    std::cout<<d<<" ";
  }

  return 0;
}
