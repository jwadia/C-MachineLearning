#include "Matrix.h"

Matrix::Matrix(std::vector<std::vector<double>> insert) {
  matrix = insert;
}

Matrix::Matrix(std::vector<std::vector<double>> insert, std::vector<std::vector<double>> ans) {
  matrix = insert;
  matrix_aug = ans;
}

double Matrix::determinant() {
  if(matrix.size() == matrix[0].size()) {
    return determinant(matrix);
  } else {
    throw "determinant_error";
  }
}

double Matrix::determinant(std::vector<std::vector<double>> m) {
  std::vector<double> coefficient;
  std::vector<std::vector<std::vector<double>>> miniMatrix;
  std::vector<double> row;
  std::vector<std::vector<double>> col;
  double det = 0;

  if(m.size() == 2 && m[0].size() == 2) {
    return (m[0][0]*m[1][1])-(m[0][1]*m[1][0]);
  } else {
    for(int i = 0; i < m.size(); i++) {
      coefficient.push_back(m[0][i]);
      for(int j = 1; j < m.size(); j++) {
        for(int k = 0; k < m.size(); k++) {
          if(i!=k) {
            row.push_back(m[j][k]);
          }
        }
        col.push_back(row);
        row.clear();
      }
      miniMatrix.push_back(col);
      col.clear();
    }
    det+=coefficient[0]*determinant(miniMatrix[0]);
    for(int i = 1; i < coefficient.size(); i++) {
      if(i%2 == 0) {
        det+=coefficient[i]*determinant(miniMatrix[i]);
      } else {
        det-=coefficient[i]*determinant(miniMatrix[i]);
      }
    }
    return det;
  }
}

std::vector<double> Matrix::solve() {
  if(matrix[0].size() == matrix_aug.size()) {

    double det = determinant(matrix);
    std::vector<double> col;
    std::vector<double> coefficient;
    std::vector<std::vector<double>> miniMatrix;

    for(int h = 0; h < matrix[0].size(); h++) {
      for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[0].size(); j++) {
          if(h==j) {
            col.push_back(matrix_aug[i][0]);
          } else {
            col.push_back(matrix[i][j]);
          }
        }
        miniMatrix.push_back(col);
        col.clear();
      }
      coefficient.push_back(determinant(miniMatrix)/det);
      miniMatrix.clear();
    }
    return coefficient;
  } else {
    throw "solve_error";
  }
}
