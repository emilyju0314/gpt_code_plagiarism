#include<iostream>
#include<cmath>
using namespace std;
double R=6378.1;
int main()
{
	double a,b,c,d;
	while(cin>>a>>b>>c>>d,b>=0)
	{
		double x1,x2,y1,y2,z1,z2;
		double p1=a/180*M_PI,r1=b/180*M_PI,p2=c/180*M_PI,r2=d/180*M_PI;
		x1=cos(p1)*cos(r1);
		x2=cos(p2)*cos(r2);
		y1=cos(p1)*sin(r1);
		y2=cos(p2)*sin(r2);
		z1=sin(p1);
		z2=sin(p2);
		double theta=acos((2-((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2)))/2);
		cout<<round(R*theta)<<endl;
	}
}

