#include<iostream>
#include<vector>
using namespace std;
double lagrangeInterpolation(int n,vector<double>&x,vector<double>&y,double xp)
{
    double ansyp=0;
    for(int i=0;i<n;i++)
    {
        double Li=1;
        for(int j=0;j<n;j++)
        {
            if(i!=j)
            {
               Li*=(xp-x[j])/(x[i]-x[j]);
            }
        }
        ansyp+=Li*y[i];
    }
    return ansyp;
}
int main()
{
    int n;
    cin>>n;
    vector<double>x(n),y(n);
    for(int i=0;i<n;i++) 
    cin>>x[i]>>y[i];
    double xp;
    cin>>xp;
    cout<<lagrangeInterpolation(n,x,y,xp)<<"\n";
    return 0;
}