#include<iostream>
#include<cmath>
#include<cfloat>
using namespace std;

int main()
{
    double xa,ya,xb,yb,xc,yc,xd,yd;
    double v1x,v1y,v2x,v2y;
    while(cin>>xa>>ya>>xb>>yb>>xc>>yc>>xd>>yd)
    {
        v1x = xb-xa;
        v1y = yb-ya;
        v2x = xd-xc;
        v2y = yd-yc;
        if( fabs(v1x*v2x+v1y*v2y)< DBL_MIN * 100){cout << "YES" << endl;}
        else {cout << "NO" << endl;}

    }

    return 0;
}