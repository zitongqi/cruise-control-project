#include "model.h"

CarModel::CarModel(double m, double b)
    : m(m), b(b) {}

double CarModel::derivative(double v, double u)
{
    return (u - b * v) / m;
}
