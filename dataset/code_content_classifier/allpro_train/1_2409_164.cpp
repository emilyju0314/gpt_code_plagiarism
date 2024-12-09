#include <bits/stdc++.h>
typedef long long i64;
using std::cout;
using std::endl;
using std::cin;

int main() {
	int n, k; scanf("%d %d", &n, &k); std::vector<i64> a(n);
	for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
	
	std::vector<i64> vec;
	for(int i = 0; i < n; i++) {
		i64 sum = 0;
		for(int j = i; j < n; j++) {
			sum += a[j];
			
			vec.push_back(sum);
		}
	}
	assert(vec.size() == n * (n + 1) / 2);
	
	i64 ans = 0;
	std::vector<i64> A, B;
	for(int j = 59; j >= 0; j--) {
		for(auto v : vec) {
			if(v >> j & 1) A.push_back(v);
			else B.push_back(v);
		}
		if(A.size() >= k) {
			vec.swap(A);
			ans |= 1LL << j;
		}
		A.clear();
		B.clear();
	}
	printf("%lld\n", ans);
	return 0;
}
