Cruise Control System Simulation — Academic Documentation

This repository contains an academic implementation of a simplified longitudinal cruise control system using C++ for numerical simulation and Python for visualization. The project is based on the canonical first-order vehicle dynamics model commonly used in control systems education.

The objective of this implementation is to simulate the vehicle response under a feedback controller and to examine the system behavior over a long horizon (120 seconds), consistent with standard reference literature and teaching materials.



1. System Description

The longitudinal vehicle dynamics are modeled as a first-order linear differential equation:

m * dv(t)/dt = u(t) - b * v(t)

where:

v(t): vehicle velocity (m/s)

u(t): traction force applied to the vehicle (N)

m = 1000 kg: vehicle mass

b = 50 N·s/m: linear drag (rolling + aerodynamic resistance)

Rewriting the equation:

dv(t)/dt = (u(t) - b * v(t)) / m

The system is simulated using a forward Euler integration scheme:

v(k+1) = v(k) + ((u(k) - b * v(k)) / m) * Δt


2. Project Structure

cruise-control-project/
│
├── sprint1-basic/
│   ├── main.cpp
│   ├── model.h / model.cpp
│   ├── pid.h / pid.cpp
│   ├── solver.h / solver.cpp
│   ├── velocity.csv
│   ├── plot_csv.py
│   └── velocity_plot.png
│
└── README.md

model.h / model.cpp
Implements the vehicle differential equation.

pid.h / pid.cpp
Provides a classical PID controller with saturated output.

solver.h / solver.cpp
Implements the Euler integration method.

main.cpp
Combines all components into a full 120-second numerical simulation.

plot_csv.py
Generates a velocity–time plot for analysis and comparison.

3. Control Law

A PID (Proportional–Integral–Derivative) controller is used to regulate the vehicle velocity

u(t) = Kp * e(t) + Ki * ∫ e(t) dt + Kd * de(t)/dt

where the tracking error is defined as:

e(t) = v_ref - v(t)

To ensure physical feasibility, the control force is constrained:

0 ≤ u(t) ≤ 500   (N)


4. Numerical Implementation

The simulation loop proceeds as follows:

1.Evaluate the control input using the PID controller

2.Compute acceleration from vehicle dynamics

3.Update velocity using the Euler integration method

4.Record velocity to velocity.csv

5.Repeat for a total duration of 120 seconds

The simulation uses a fixed time step:

Δt = 0.1 seconds

This dataset is later visualized to analyze transient and steady-state behavior.

5. Building and Running the Simulation
Compile the C++ source code

cd cruise-control-project/sprint1-basic
g++ main.cpp model.cpp pid.cpp solver.cpp -o main

Run the simulation

./main


his produces the file:

velocity.csv — simulated velocity trajectory

6. Visualization
Required Python packages

pandas

matplotlib

Install dependencies

sudo apt install python3-pip
pip3 install pandas matplotlib

Generate the response plot

python3 plot_csv.py

Output:

velocity_plot.png — graphical representation of the simulated velocity

A plot showing the evolution of v(t) over the 120-second horizon

7. Expected System Behavior

The system behaves as a stable first-order linear system:

Rapid initial rise in velocity

Gradual approach toward steady state

Asymptotic convergence determined by:

v_inf = u / b

For a constant input u = 500 N:

v_inf = 500 / 50 = 10 m/s

This theoretical result matches the numerical simulation and can be used to validate correctness.

