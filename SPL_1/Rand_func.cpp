#include "header.h"

//Gaussian Initialization of matrices using random number
double randfrom(double minn, double maxx)
{
    double range = (maxx - minn);
    double div = RAND_MAX / range;
    return minn + (rand() / div);
}
double exponential(){ // e^(-0.5*x^2)
    double standard_val,power, x;
    x=randfrom(-9.0,10.0);
    power=((x-sigma)/mu);
    power=pow((-0.5*power), 2);
    return pow(e, power);
}
double Rand_number(){
    return initial*exponential();
}
