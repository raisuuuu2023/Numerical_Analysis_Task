#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
double func(double x)
{
    return pow(x,5)-3*x+5;
}
double func_prime(double x)
{
    return 5*(x,4)-3;
}
int main()
{
    double x0;
    double epsilon=1e-3;
    int maxiteration=100;
    cout<<"Initial guess: ";
    cin>>x0;
    int iteration=0;
    double x1;
    cout<<fixed<<setprecision(6);
    while(iteration<maxiteration)
    {
        double fx=func(x0);
        double fpx=func_prime(x0);
        if(fpx==0)
        {
            cout<<"No convergence.\n";
            return 1;
        }
        x1=x0-fx/fpx;
        cout<<"Iteration "<<iteration+1<<": x= "<<x1<<" , func(x)= "<<func(x1)<<"\n";
        if(fabs(x1-x0)<epsilon)
        {
            cout<<"\nRoot found: "<<x1<<"after "<<iteration+1<<" iterations.\n";
            return 0;
        }
        x0=x1;
        iteration++;
    }
    cout<<"\nmethod did not converge after "<<maxiteration<<" iterations.\n";
    return 1;
}