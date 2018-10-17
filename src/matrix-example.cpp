#include <vector>
#include <iostream>
#include "util/Matrix.h"

int main() {
  std::vector<std::vector<double>> matrix = {
  {1,0,2,5,2},
  {0,2,5,3,7},
  {4,-3,0,2,9},
  {4,-3,4,2,2},
  {5,-3,0,1,9}
  };
  std::vector<std::vector<double>> ans = {
  {9},
  {8},
  {-2},
  {5},
  {-1}
  };

  Matrix m(matrix);
  Matrix m2(matrix, ans);

  std::cout<<"Determinant: "<<m.determinant()<<"\n";

  int j = 1;
  for(double i : m2.solve()) {
    std::cout<<"X"<<j<<"="<<i<<"\n";
    j++;
  }

  return 0;
}
