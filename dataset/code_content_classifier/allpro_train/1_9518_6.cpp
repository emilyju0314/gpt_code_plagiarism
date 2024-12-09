#include <bits/stdc++.h>
using namespace std;

__int128 N;
__int128 f(__int128 x){
	return (N+2*x-1) / (2*x);
}

__int128 s1(long long N){
	__int128 sum = 0;
	long long T= sqrt(N/2) - 1e-10;
	T++;
	__int128 now = N/2;
	for(long long i = 1 ; i <= T ; i++){
		sum += N/2 - now;
		sum += N/2 - now;
		now = f(i);
	}
	sum += (__int128)(N/2-T) * (N/2-T);
	
	return sum;
}

int main(){
	long long N_;
	while( cin >> N_ && N_ ){
		N = N_;
		__int128 sum = s1(N);
		__int128 result = 4*(2*N)+2*N*N-8*sum;
		string s;
		while( result > 0 ){
			s = string(1,'0'+(int)(result%10)) + s;
			result /= 10;
		}
		cout << s << endl;
		
	}
}