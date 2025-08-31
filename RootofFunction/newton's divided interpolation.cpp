#include<iostream>
#include<vector>
using namespace std;
vector<vector<double>>dividedDifferenceTable(int n,vector<double>&x,vector<double>&y)
{
    vector<vector<double>>table(n,vector<double>(n,0));
    for(int i=0;i<n;i++)
    table[i][0]=y[i];
    for(int j=1;j<n;j++)
    {
        for(int i=0;i<n-j;i++)
        {
            table[i][j]=(table[i+1][j-1]-table[i][j-1])/(x[i+j]-x[i]);
        }
    }
    return table;
}
double newtonInterpolation(int n,vector<vector<double>>table,vector<double>&x,double xp)
{
    double result=table[0][0];
    double term=1;
    for(int i=1;i<n;i++)
    {
        term*=(xp-x[i-1]);
        result+=table[0][i]*term;
    }
    return result;
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
    auto table=dividedDifferenceTable(n,x,y);
    cout<<newtonInterpolation(n,table,x,xp)<<"\n";
    return 0;
}