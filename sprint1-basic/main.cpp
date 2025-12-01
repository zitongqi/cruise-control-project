#include <iostream>
#include <fstream>
#include <vector>

#include "model.h"
#include "pid.h"
#include "solver.h"

// Visualization Utils
void printASCIIPlot(const std::vector<double>& data, double max_val) {
    std::cout << "\n=== Velocity Visualization (ASCII) ===\n";
    std::cout << "Target: " << max_val << " m/s\n\n";

    int step_size = (int)(data.size() / 20); // Downsampling: Calculate step size to print approx. 20 lines
    if (step_size < 1) step_size = 1;

    for (size_t i = 0; i < data.size(); i += step_size) {
        double val = data[i];

        int bar_len = static_cast<int>((val / max_val) * 50); // Calculate bar length, scaled to a max width of 50 chars
        if (bar_len < 0) bar_len = 0;

        std::string bar(bar_len, '#'); 
        printf("Step %4zu | %s  %.2f m/s\n", i, bar.c_str(), val);
    }
}

// Main Application
int main()
{
    // System Initialization
    double m = 1000.0;
    double b = 50.0; // [Ns/m]

    CarModel car(m, b);
    PID pid(800.0, 40.0, 0.0); // Kp = 800 [N/(ms)], Ki = 40 [N/m]

    double dt = 0.1;
    double sim_time = 120.0;
    double v = 0.0;

    double target_speed = 10.0;  // [m/s]
    
    // Performance Benchmark
    // Sprint 3 Benchmark
    std::cout << "Starting Performance Test (Running 100,000 simulations)..." << std::endl;

    // Start Timer
    auto start_time = std::chrono::high_resolution_clock::now();

    // Benchmark Loop
    int iterations = 100000;
    std::vector<double> results;

    // Stop Timer
    for (int i = 0; i < iterations; i++) {
        results = mySolver.simulate(myCar, myPID, target_speed, sim_time, dt);
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end_time - start_time;

    std::cout << "--------------------------------------" << std::endl;
    std::cout << "Time taken: " << diff.count() << " seconds." << std::endl;
    std::cout << "--------------------------------------" << std::endl;

    // 3. Validation
    printASCIIPlot(results, target_speed);

    return 0;
}
