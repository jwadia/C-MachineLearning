#include "Regression.h"
#include "../util/Matrix.h"
#include <math.h>

Regression::Regression(std::vector<double> xList, std::vector<double> yList) {
  x = xList;
  y = yList;
}
 std::vector<double> Regression::PolynomialRegression(int order) {
   if(x.size() == y.size()) {
     int n = x.size();
     double sum = 0;
     std::vector<double> row;
     std::vector<std::vector<double>> matrix;
     std::vector<std::vector<double>> ans;

     for(int i = 0; i <= order; i++) {
       for(int j = 0; j <= order; j++) {
         if(i == 0 && j == 0) {
           row.push_back(n);
         } else {
           for(double k : x) {
             sum+=pow(k,j+i);
           }
           row.push_back(sum);
           sum = 0;
         }
       }
       matrix.push_back(row);
       row.clear();
     }
     for(int i = 0; i <= order; i++) {
       for(int j = 0; j <= n; j++) {
         sum+=(pow(x[j],i)*y[j]);
       }
       ans.push_back({sum});
       sum = 0;
     }

     Matrix m(matrix, ans);
     return m.solve();
   }
 }
