#define _USE_MATH_DEFINES

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main(){
	
	int N;
	long long int P;
	cin >> N >> P;
	
	long long int A[200000];
	long long int sum = 0;
	
	for(int i = 0; i < N; i++){
		long long int w, b;
		cin >> w >> b;
		A[i] = -(100 - P) * w - P * b;
		sum += P * b;
	}
	
	sort(A, A + N);
	
	int ans = 0;
	for(int i = 0; i < N; i++){
		sum += A[i];
		if(sum <= 0){
			ans = i + 1;
			break;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}