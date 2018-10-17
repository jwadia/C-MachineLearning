#ifndef __Matrix_H_INCLUDED__
#define __Matrix_H_INCLUDED__

#include <vector>

class Matrix {
  private:
    std::vector<std::vector<double>> matrix;
    std::vector<std::vector<double>> matrix_aug;
    double determinant(std::vector<std::vector<double>> matrix);
  public:
    Matrix(std::vector<std::vector<double>> insert);
    Matrix(std::vector<std::vector<double>> insert, std::vector<std::vector<double>> ans);
    double determinant();
    std::vector<double> solve();
};

#endif
