#ifndef __Regression_H_INCLUDED__
#define __Regression_H_INCLUDED__

#include <vector>
#include <iostream>

class Regression {
  private:
    std::vector<double> x;
    std::vector<double> y;
  public:
    Regression(std::vector<double> xList, std::vector<double> yList);
    std::vector<double> PolynomialRegression(int order);
};

#endif
