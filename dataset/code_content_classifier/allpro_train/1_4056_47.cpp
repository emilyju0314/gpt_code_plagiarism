#include<iostream>
#include<cstdio>

#define MAX 1000000

using namespace std;

int eratos[MAX];
int primes[MAX];
int max_primes;

void MakePrimes(){
	int n = 0;
	eratos[0] = 1;
	eratos[1] = 1;
	eratos[2] = 0;
	for(int i = 2; i < MAX; ++i){
		if( eratos[i] == 0 ){
			for(int j = 2; i * j < MAX; ++j){
				eratos[i*j] = 1;
			}
			primes[n++] = i;
		}
	}
	primes[n++] = 1000003;
	max_primes = n;
}
int bin_search_prime(int n){
	int r = max_primes - 1, l = 0, m;

	while( r > l + 1 ){
		m = ( r + l ) / 2; 
		if( primes[m] > n )
			r = m;
		else if( primes[m] < n )
			l = m;
		else
			return m;
	}
	return l;
}

int main()
{
	MakePrimes();
	while(true){
		int n;
		int ans = 0;
		
		scanf("%d", &n);
		if( n == 0 ) break;

		for(int i = 0 ; i < n ; ++i){
			int X = 0;
			int p,m;
			scanf("%d%d", &p,&m);

			int l = bin_search_prime( std::max(0,p - m) );
			int r = bin_search_prime( std::min(MAX-1,p + m) );
			
			if( primes[l] < p-m ) ++l;
			X = (r - l) + 1;

			ans += X - 1;
		}

		printf("%d\n", ans);
	}
	return 0;
}