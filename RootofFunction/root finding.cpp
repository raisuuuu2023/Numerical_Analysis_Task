#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
double func(double x)
{
    return 4*x*x+3*x-3;
}
void Bisection(double a, double b, double epsilon) {
    double fa = func(a);
    double fb = func(b);

    if (fa * fb >= 0) {
        return;
    }
    double c,fc;
    int it=0;
    cout << fixed << setprecision(6);
    while((b-a)/2.00>=epsilon)
    {
        c = (a + b) / 2.0;
        fc = func(c);

        cout << it+ 1 << a  << b  << c  << fc << "\n";

        if (fabs(fc) < epsilon)
            break;

        if (fa * fc < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }

        it++;
    }
    cout << "\n Approximate Root: " << (a + b) / 2.0 << endl;
    cout << "Total Iterations: " << it << endl;
}
int main()
{
     double a,b;
     double epsilon=0.000001;
     cin>>a>>b;
     Bisection(a,b,epsilon);
     return 0;
}