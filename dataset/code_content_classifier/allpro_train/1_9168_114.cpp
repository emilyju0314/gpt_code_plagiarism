#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cstring>
using namespace std;
typedef long long int ll;

const int N=1299709+10;

bool not_prime[N];
vector<int> prime;

void make_prime(){
	not_prime[0]=not_prime[1]=1;
	for(int i=2;i<N;i++){
		if(!not_prime[i]){
			prime.push_back(i);
			for(int j=i+i;j<N;j+=i){
				not_prime[j]=1;
			}
		}
	}
}

int n;

void solve(){
	if(!not_prime[n]){
		printf("0\n");
		return;
	}
	auto it=lower_bound(prime.begin(),prime.end(),n);
	auto it2=it;
	it--;
	printf("%d\n",*it2-*it);
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	make_prime();
	while(1){
		cin >> n;
		if(n==0)break;
		solve();
	}
}
