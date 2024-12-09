#include <bits/stdc++.h>
using namespace std;

int main()
{
	int K;
	cin >> K;

	queue<long long> que;
	for( int x = 1; x < 10; x++ ) que.push( x );
	long long ans;
	for( int i = 0; i < K; i++ ) {
		ans = que.front();
		que.pop();
		int t = ans % 10;
		if( t ) que.push( ans * 10 + t - 1 );
		que.push( ans * 10 + t );
		if( t != 9 ) que.push( ans * 10 + t + 1 );
	}
	cout << ans << endl;
}
