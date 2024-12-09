#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <numeric>
#include <utility>

#define rep(i,n)	for(int i = 0;i < n;i++)
#define rep2(i,n)	for(int i = 1;i <= n;i++)
#define each(i,x)	for(auto & i : x)

using namespace std;

int main()
{
	int p = 1;
	int n;
	cin >> n;
	while(n)
	{
		vector<int> xa;
		vector<int> ya;
		rep(i,n)
		{
			int x,y;
			cin >> x >> y;
			xa.push_back(x);
			ya.push_back(y);
		}
		double s = 0;
		rep(i,n)
		{
			s += xa[i]*ya[(i+1)%n]-xa[(i+1)%n]*ya[i];
		}
		printf("%d %.1lf\n",p,abs(s)/2.0);
		cin >> n;
		p++;
	}
	return 0;
}