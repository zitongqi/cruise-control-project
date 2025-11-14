#include "solver.h"

double Solver::euler(double v, double dvdt, double dt)
{
    return v + dvdt * dt;
}
