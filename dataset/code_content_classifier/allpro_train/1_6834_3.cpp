#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

vector<int>primes;
void hurui(const int amax) {
	static bool flag = false;
	if (flag)return;
	vector<int>sos;
	sos = vector<int>(amax + 1, true);
	sos[0] = false; sos[1] = false;
	for (int i = 2; i <= amax; ++i) {
		if (sos[i]) {
			for (int j = 2 * i; j <= amax; j += i)sos[j] = false;
		}
	}
	for (int i = 0; i <= amax; ++i) {
		if (sos[i]) {
			primes.push_back(i);
		}
	}
	flag = true;
}
map<long long int, int>soinnsuu(long long int a) {
	hurui(1e6);
	map<long long int, int>ans;
	for (auto i : primes) {
		if (i> a)break;
		while (a%i == 0) {
			ans[i]++;
			a /= i;
		}
	}
	if (a != 1)ans[a]++;
	return ans;
}

int main() {
	int N,M;cin>>N>>M;
	auto n_mp(soinnsuu(N));
	map<int,bool>valid_mp;
	for (auto nm : n_mp) {
		valid_mp[nm.first]=false;
	}
	for (int i = 0; i < M; ++i) {
		int num;cin>>num;
		for (auto nm : n_mp) {
			if (num%nm.first) {
				valid_mp[nm.first]=true;
			}
		}
	}
	bool ok = all_of(valid_mp.begin(), valid_mp.end(), [](const pair<int, bool>&p) {
		return p.second;
	});
	if(ok)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}