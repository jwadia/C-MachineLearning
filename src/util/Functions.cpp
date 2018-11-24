#include "Functions.h"

Functions::Functions() {

}

double Functions::sigmoid(double input) {
  return (1/(1+pow(2.7182281828, -1*input)));
}

double Functions::dsigmoid(double input) {
  return (pow(2.7182281828, -1*input)/pow((1+pow(2.7182281828, -1*input)), 2));
}
