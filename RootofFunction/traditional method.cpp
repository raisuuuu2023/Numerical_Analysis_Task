#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return 3*x-cos(x)-1;
}

void traditionalBisection(double a, double b, double epsilon) {
    if (f(a) * f(b) >= 0) {
        cout << "Invalid interval. f(a) and f(b) must have opposite signs." << endl;
        return;
    }

    double c=a;
    int iterations=0;

    while ((b - a) >= epsilon) {
        
        c = (a + b) / 2;

        
        if (fabs(f(c)) < epsilon)
            break;

        
        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;

        iterations++;
    }

    cout << "The root is: "<<c<<endl;
    cout << "Total iterations: " << iterations << endl;
}

int main() {
    double a = 0, b = 1, epsilon = 1e-6;
    traditionalBisection(a, b, epsilon);
    return 0;
}