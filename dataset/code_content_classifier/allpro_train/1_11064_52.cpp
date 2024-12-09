#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int digits(int n){
	int count = 0; 
	while(n > 0){
		count ++; 
		n /= 2; 
	}
	return count; 
}
int ketawa(int n){
	int sum = 0; 
	while(n > 0){
		sum += n % 2; 
		n /= 2; 
	}
	return sum; 
}
int main(){
	int L; 
	cin >> L; 
	int N = digits(L); 
	int M = N * 2 + ketawa(L) - 3; 
	cout << N << " " << M << endl; 
	for(int i = 1; i < N; i++){
		cout << i << " " << i+1 << " " << 0 << endl; 
		cout << i << " " << i+1 << " " << (1 << (N - 1 - i)) << endl; 
	}
	for(int i = 2; i <= N; i++){
		int a = (L >> (N-i)); 
		if(a % 2) cout << 1 << " " << i << " " << ((a >> 1) << (N-i+1)) << endl; 
	}
}