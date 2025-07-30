#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x) {
    return 3 * x - cos(x) - 1;
}

void optimizedBisection(double a, double b, double epsilon) {
    double fa = f(a);
    double fb = f(b);

    if (fa * fb >= 0) {
        cout << "Invalid interval: f(a) and f(b) must have opposite signs." << endl;
        return;
    }

    double c, fc;
    int iterations = 0;

    cout << fixed << setprecision(6);
    cout << "Iter\t a\t\t b\t\t c\t\t f(c)\n";

    while ((b - a) / 2.0 > epsilon) {
        c = (a + b) / 2.0;
        fc = f(c);

        cout << iterations + 1 << "\t " << a << "\t " << b << "\t " << c << "\t " << fc << "\n";

        if (fabs(fc) < epsilon)
            break;

        if (fa * fc < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }

        iterations++;
    }

    cout << "\n Approximate Root: " << (a + b) / 2.0 << endl;
    cout << "Total Iterations: " << iterations << endl;
}

int main() {
    double a, b, epsilon;

    cout << "Enter interval a and b (a < b): ";
    cin >> a >> b;

    cout << "Enter tolerance epsilon (e.g. 1e-6): ";
    cin >> epsilon;

    optimizedBisection(a, b, epsilon);
    return 0;
}
