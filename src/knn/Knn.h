#ifndef __KNN_INCLUDED__
#define __KNN_H_INCLUDED__

#include <vector>
#include <math.h>

class KNN {
  private:
    std::vector<double> x;
    std::vector<double> y;
    std::vector<double> label;
    int k;
  public:
    KNN(std::vector<double> xList, std::vector<double> yList, std::vector<double> lList, int num);
    double predict(double px, double py);
};

#endif
