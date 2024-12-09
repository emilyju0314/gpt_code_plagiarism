#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct BIT {
	int n;
	vector<T> value;
	BIT(int n): n(n), value(n + 1){}
	
	void add(int k, T x){
		while (k <= n){
			value[k] += x;
			k += k & -k;
		}
	}
	
	T sum(int k){
		T s = 0;
		while (k){
			s += value[k];
			k -= k & -k;
		}
		return s;
	}
	
	void add(int s, int t, T x){
		add(t, x);
		if (s > 1) add(s - 1, -x);
	}
	
	T sum(int s, int t){
		return sum(t) - sum(s - 1);
	}
};

typedef long long lint;
const lint MOD = 1e9 + 7;
lint fact[100001];

int main()
{
	fact[0] = 1;
	for (int i = 1; i <= 100000; i++){
		fact[i] = (fact[i - 1] * i) % MOD;
	}
	
	int n, r;
	while (scanf("%d", &n), n){
		vector<int> v(n);
		BIT<lint> bit(n);
		for (int i = 0; i < n; i++){
			v[i] = i + 1;
			bit.add(i + 1, 1);
		}
		
		scanf("%d", &r);
		for (int i = 0; i < r; i++){
			int s, t;
			scanf("%d %d", &s, &t);
			swap(v[--s], v[--t]);
		}
		
		lint res = 0;
		for (int i = 0; i < n; i++){
			bit.add(v[i], -1);
			res += (bit.sum(v[i]) * fact[n - i - 1]);
			res %= MOD;
		}
		
		printf("%lld\n", res);
	}
	
	return 0;
}