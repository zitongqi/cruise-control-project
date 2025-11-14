#ifndef PID_H
#define PID_H

class PID {
public:
    PID(double kp, double ki, double kd);

    double compute(double setpoint, double v, double dt);

private:
    double kp, ki, kd;
    double integral;
    double prev_error;
};

#endif
