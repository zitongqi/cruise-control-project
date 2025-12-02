#include <iostream>
#include <fstream>
#include <vector>

#include "model.h"
#include "pid.h"
#include "solver.h"

int main()
{
    double m = 1000.0;
    double b = 50.0;

    CarModel car(m, b);
    PID pid(10.0, 1.0, 0.5);

    double dt = 0.1;
    double sim_time = 120.0;
    double v = 0.0;

    double target_speed = 20.0;  // m/s

    std::vector<double> velocity_log;

    for(double t = 0; t < sim_time; t += dt)
    {
        double u = pid.compute(target_speed, v, dt);
        double dvdt = car.derivative(v, u);

        v = Solver::euler(v, dvdt, dt);

        velocity_log.push_back(v);
    }

    std::ofstream file("velocity.csv");
    for(double vel : velocity_log)
        file << vel << "\n";

    std::cout << "Simulation complete!\n";

    return 0;
}
