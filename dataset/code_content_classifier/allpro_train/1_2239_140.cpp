#include <bits/stdc++.h>
using namespace std;
vector<int> primes;
bool isPrime(long long x){
	for(long long i = 2; i * i <= x; i++) if(x % i == 0) return false;
	return true;
}
void init(){
	for(int i = 2; i <= 3000; i++) if(isPrime(i)) primes.push_back(i);
}
int main(){
	init();
	int n;
	cin >> n;
	unordered_map<long long, long long> rev, occ;
	for(int i = 0; i < n; i++){
		long long x; cin >> x;
		long long Norm = 1, Pair = 1;
		for(int v : primes){
			int cnt = 0;
			while(x % v == 0) x /= v, cnt++;
			cnt %= 3;
			if(!cnt) continue;
			if(cnt == 1){
				Norm *= v;
				Pair *= v;
				Pair *= v;
			} else {
				Norm *= v;
				Norm *= v;
				Pair *= v;
			}
		}
		if(x > 1){
			long long sq = sqrtl(x);
			while(sq * sq <= x) sq++;
			while(sq * sq > x) sq--;
			if(sq * sq == x){
				Norm *= x;
				Pair *= sq;
			} else {
				Norm *= x;
				Pair *= x;
				Pair *= x;
			}
		}
		rev[Norm] = Pair;
		rev[Pair] = Norm;
		occ[Norm]++;
		occ[Pair];
	}
	int ans = 0;
	for(auto it : occ) if(it.first != 1) ans += max(it.second, occ[rev[it.first]]);
	ans /= 2;
	if(occ[1]) ans++;
	cout << ans << endl;
	return 0;
}
