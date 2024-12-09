#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
ll read()
{
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
struct Point{double x,y;};
struct Circle{Point x;double r;}c0,c1;
Point operator +(Point a,Point b){return (Point){a.x+b.x,a.y+b.y};}
Point operator -(Point a,Point b){return (Point){a.x-b.x,a.y-b.y};}
Point operator *(Point a,double b){return (Point){a.x*b,a.y*b};}
bool operator >(Point a,Point b){return a.x>b.x||(a.x==b.x&&a.y>b.y);}
double arg(Point a){return atan2(a.y,a.x);}
Point polar(double a,double b){return (Point){a*cos(b),a*sin(b)};}
double norm(Point a){return a.x*a.x+a.y*a.y;}
double abs(Point a){return sqrt(norm(a));}
void read(Point &a){a.x=read(),a.y=read();}
void read(Circle &a){read(a.x),a.r=read();}
void print(Point a){printf("%.8lf %.8lf",a.x,a.y);}
pair<Point,Point>getintersection(Circle c0,Circle c1)
{
	double t=arg(c1.x-c0.x),d=abs(c1.x-c0.x);
	double a=acos((c0.r*c0.r+d*d-c1.r*c1.r)/(2*d*c0.r));
	return make_pair(c0.x+polar(c0.r,t+a),c0.x+polar(c0.r,t-a));
}
int main()
{
	read(c0),read(c1);
	pair<Point,Point>ans=getintersection(c0,c1);
	if(ans.first>ans.second)swap(ans.first,ans.second);
	print(ans.first);putchar(' ');print(ans.second);
	return printf("\n"),0;
}

