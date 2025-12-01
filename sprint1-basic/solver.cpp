#include "solver.h"
#include <cmath> 

// Default Constructor
Solver::Solver() {}

// @brief Executes the simulation loop using Euler integration.
std::vector<double> Solver::simulate(CarModel& car, PID& pid, double target_speed, double sim_time, double dt) {
    std::vector<double> velocity_log;

    // Sprint 3 Core Optimization: Memory Reservation
    size_t predicted_size = (size_t)(sim_time / dt) + 10;

    velocity_log.reserve(predicted_size);

    double v = 0.0;

    // Simulation Loop
    for (double t = 0; t < sim_time; t += dt) {
        double u = pid.compute(target_speed, v, dt);
        double dvdt = car.derivative(v, u);
        v = v + dvdt * dt;// Update velocity (Euler Integration)

        // Store value. Since we used 'reserve', this is now a simple assignment 
        velocity_log.push_back(v);
    }

    return velocity_log;
}
