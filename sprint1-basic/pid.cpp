#include "pid.h"

PID::PID(double kp, double ki, double kd)
    : kp(kp), ki(ki), kd(kd), integral(0.0), prev_error(0.0) {}

double PID::compute(double setpoint, double v, double dt)
{
    double error = setpoint - v;

    integral += error * dt;
    double derivative = (error - prev_error) / dt;
    prev_error = error;

    double u = kp*error + ki*integral + kd*derivative;

    // Course Requirement Example: u Maximum 500 N
    if (u > 500) u = 500;
    if (u < 0) u = 0;

    return u;
}
