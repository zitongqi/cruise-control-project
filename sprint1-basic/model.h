#ifndef MODEL_H
#define MODEL_H

class CarModel
{
public:
    CarModel(double m, double b);
    double derivative(double v, double u);

private:
    double m;
    double b;
};


#endif
