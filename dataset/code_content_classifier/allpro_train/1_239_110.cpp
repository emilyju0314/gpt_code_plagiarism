#include<iostream>
#include<queue>

int n;
int a, b;
int c;
int ans;
std::priority_queue<int> p, q;

int main()
{
	std::cin >> n;
	std::cin >> a >> b;
	std::cin >> c;
	for( int i = 0; i < n; i++ ){
		int d;
		std::cin >> d;
		p.push( d );
	}
	
	q = p;
	
	for( int k = 0; k <= n; k++ ){
		int s = c;
		for( int i = 0; i < k; i++ ){
			s += q.top(); q.pop();
		}
		ans = std::max( ans, s / ( a + b * k ) );
		q = p;
	}
	
	std::cout << ans << std::endl;

 	return 0;
}