#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>

#define MEMZERO(x) memset(x, 0, sizeof(x));

using namespace std;

int main ( void )
{
	const int dx[] = { 0, 0, 0, -1, 1, -1, 1, -1, 1, 0, 0, -2, 2 };
	const int dy[] = { 0, -1, 1, 0, 0, -1, -1, 1, 1, -2, 2, 0, 0 };
	int p[10][10];
	int x, y, s;
	
	MEMZERO(p);
	
	while(~scanf("%d,%d,%d", &x, &y, &s))
	{
		s *= 4;
		for ( int i = 0; i <= s; ++i )
		{
			int mx = x + dx[i];
			int my = y + dy[i];
			if ( 0 <= mx && mx < 10 && 0 <= my && my < 10 )
			{
				++p[my][mx];
			}
		}
	}
	
	int cnt = 0, val = 0;
	
	for ( int i = 0; i < 10; ++i )
		for ( int j = 0; j < 10; ++j )
			if(!p[i][j])
				++cnt;
			else
				val = max(val, p[i][j]);
	cout << cnt << endl << val << endl;
	
	return 0;
}