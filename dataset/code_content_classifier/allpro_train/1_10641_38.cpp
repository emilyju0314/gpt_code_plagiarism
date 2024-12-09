#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdio>
#include<ctime>
#include <algorithm>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double eps = 1e-8;
int n;
/*
机选取一个点作为初始解，然后不断向当前距离最远点靠近，这是一个不断调整的过程，
将对应模拟淬火算法中不断向内能最低（半径最小）这一目标函数逼近，温度对应控制变量。
*/
struct Point
{
	double x,y,z;
	Point(double x = 0, double y = 0, double z = 0)
	{
		x = x;
		y = y;
		z = z;	
	}
}p[1010];
double dis(Point a, Point b)
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y)+(a.z-b.z)*(a.z - b.z) );
}

void solve()
{
	/*
	不要用随机取点，取不到结果
	*/
	Point temp = p[1];
	double ans = 9999999;
	double T = 100.0;
	while( T > eps)//如果温度小于eps，则达到最优解
	{
		int k = 1;
		for (int i = 1; i <= n; i++)
		{
			if (dis(temp, p[i]) > dis(temp, p[k]))
				k = i;//寻找距离temp最远的点
		}
		double dista = dis(temp, p[k]);
		ans = min(ans, dista);//找出该点的最小距离

			temp.x += (p[k].x - temp.x) / dista * T;
			//离temp最远的点与temp的x坐标差/两点最小距离*温度
			temp.y += (p[k].y - temp.y) / dista * T;
			temp.z += (p[k].z - temp.z) / dista * T;
		T *= 0.988;//降火的幅度
	}
	printf("%.5f\n", ans);
}

int main()
{
	std::ios::sync_with_stdio(false);
	while (cin>> n)
	{
		
		if (n == 0)break;
		memset(p, 0, sizeof(p));
		for (int i = 1; i <= n; i++)
		{
			cin >> p[i].x >> p[i].y>>p[i].z;
		}
		solve();
	}
}
