#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<numeric>
#include<iostream>
#include<array>
#include<string>
#include<sstream>
#include<stack>
#include<queue>
#include<list>
#include<functional>
#define _USE_MATH_DEFINES

#include<math.h>
#include<map>

#define INF 200000000

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;

struct OwnVector2
{
	double x, y;
	OwnVector2(double x, double y) :x(x), y(y) {}
	OwnVector2() :OwnVector2(0, 0) {}
	OwnVector2 operator+(const OwnVector2& v)const
	{
		return OwnVector2(x + v.x, y + v.y);
	}
	OwnVector2 operator-(const OwnVector2& v)const
	{
		return OwnVector2(x - v.x, y - v.y);
	}
	OwnVector2 operator*(const double v)const
	{
		return OwnVector2(x*v, y*v);
	}
	bool operator==(const OwnVector2& v)const
	{
		return abs(x - v.x) <= 0.0000000000001&&abs(y - v.y) <= 0.00000000000001;
	}
	bool operator!=(const OwnVector2& v)const
	{
		return abs(x - v.x) > 0.0000000000001 || abs(y - v.y) > 0.00000000000001;
	}

	double dot(const OwnVector2& v)const
	{
		return x*v.x + y*v.y;
	}
	double cross(const OwnVector2& v)const
	{
		return x*v.y - y*v.x;
	}
	double length()const
	{
		return sqrt(x*x + y*y);
	}
	double length2()const
	{
		return x*x + y*y;
	}
};

OwnVector2 vertices[100];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int q;
	cin >> q;

	for (int i = 0; i < q; i++)
	{
		double x, y;
		cin >> x >> y;
		vertices[i] = OwnVector2(x, y);
	}

	bool isConvex = true;
	for (int i = 0; i < q; i++)
	{
		OwnVector2 front, back;
		front = vertices[(i + 1) % q] - vertices[i];
		back = vertices[(i + q - 1) % q] - vertices[i];

		if (front.cross(back) < 0)
		{
			isConvex = false;
			break;
		}
	}

	printf(isConvex ? "1\n" : "0\n");
	
	return 0;
}
