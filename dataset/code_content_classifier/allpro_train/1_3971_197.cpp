#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
	pair<int, int> a[5];
	while (true) {
		int x, y;
		for (int i=0; i<5; ++i) {
			scanf("%d%d", &x, &y);
			if (x==0 && y==0) return 0;
			a[i] = make_pair(x+y, i);
		}
		sort(a, a+5);
		printf("%c %d\n", 'A'+a[4].second, a[4].first);
	}
	return 0;
}