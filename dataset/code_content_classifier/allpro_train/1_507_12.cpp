#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>

std::vector <std::pair <double, double> > list;

double l, m, r;

inline std::pair <double, double> operator + (std::pair <double, double> a, std::pair <double, double> b)
{
	return std::make_pair(a.first + b.first, a.second + b.second);
}

inline std::pair <double, double> operator - (std::pair <double, double> a, std::pair <double, double> b)
{
	return std::make_pair(a.first - b.second, a.second - b.first);
}

inline std::pair <double, double> inter(std::pair <double, double> a, std::pair <double, double> b)
{
	return std::make_pair(std::max(a.first, b.first), std::min(a.second, b.second));
}

inline bool check(double x)
{
	std::pair <double, double> delta = std::make_pair(r * x, l * x);
	std::vector <std::pair <double, double> > tmp;
	bool flag = false;
	for (int i = 0; i < (int)list.size(); i ++)
	{
		std::pair <double, double> now = inter(list[i] + delta, std::make_pair(-m, m));
		if (now.first <= now.second)
		{
			flag = true;
			tmp.push_back(now);
		}
		now = inter(list[i] - delta, std::make_pair(-m, m));
		if (now.first <= now.second)
		{
			flag = true;
			tmp.push_back(now);
		}
	}
	list.clear();
	if (!flag)
		return false;
	std::sort(tmp.begin(), tmp.end());
	for (int i = 0; i < (int)tmp.size(); i ++)
	{
		double nowr = tmp[i].second;
		int r = i;
		while (r + 1 < (int)tmp.size() && tmp[r + 1].second <= nowr)
		{
			r ++;
			nowr = std::max(nowr, tmp[r].second);
		}
		list.push_back(std::make_pair(tmp[i].first, nowr));
		i = r;
	}
	return true;
}

int main()
{
	int n;
	scanf("%d%lf%lf%lf", &n, &l, &m, &r);
	assert(n <= 1000);
	l /= 2;
	list.push_back(std::make_pair(0, 0));
	bool ans = true;
	for (int i = 1; i <= n; i ++)
	{
		double x;
		scanf("%lf", &x);
		if (ans)
			ans = check(x);
	}
	if (ans)
		puts("Yes");
	else
		puts("No");
	return 0;
}