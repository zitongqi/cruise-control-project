#ifndef SOLVER_H
#define SOLVER_H

#include <vector>       
#include "model.h"      
#include "pid.h" 

// Class Definition: Numerical Solver
class Solver {
public:

    // Constructor
    Solver();
    
    // @brief Runs the simulation loop.
    std::vector<double> simulate(CarModel& car, PID& pid, double target_speed, double sim_time, double dt);
};

#endif
