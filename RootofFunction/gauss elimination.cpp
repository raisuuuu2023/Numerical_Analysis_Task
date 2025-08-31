#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
void gaussElimination(vector<vector<double>>&a,vector<double>&b,int n) {
   
    for (int i = 0; i < n; i++) { 
        int row = i;
        for (int k = i + 1; k < n; k++) {
            if (abs(a[k][i]) > abs(a[row][i])) {
                row = k;
            }
        }   
        for (int k = i; k < n; k++) {
            swap(a[row][k], a[i][k]);
        }
        swap(b[row], b[i]);  
        for (int j = i + 1; j < n; j++) {
            double f= a[j][i] / a[i][i];
            for (int k = i; k < n; k++) {
                a[j][k] -= f * a[i][k];
            }
            b[j] -=f*b[i];
        }
    } 
    vector<double> x(n);
    for (int i=n-1;i>=0;i--) {
        x[i] = b[i];
        for (int j = i + 1; j < n; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }
    for (int i = 0; i < n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<vector<double> > a(n, vector<double>(n));
    vector<double> b(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    gaussElimination(a, b, n);
    return 0;
}