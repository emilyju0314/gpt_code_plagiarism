#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long llp;
#define mod 1000000007
#define deb(x) cerr << '\t' << "[" << #x << ": "<< x << "]\n";
#define f first
#define s second
#define pb push_back
/*
 numeric_limits<llp>::max();
 */
void solution(/*ll tc = 0*/);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    llp tc = 1;
    cin >> tc;
    for (llp t = 0; t < tc; ++t) solution(/*t*/);


    return 0;
}

void solution(/*ll tc = 0*/) {
	int n, k;
	cin >> n >> k;
	if(k / n > 0) cout << (k % n ? k/n+1 : k/n) << '\n';
	else {
		//n > k
		int t = n / k;
		if(n % k !=	0) t++;
		k *= t;
		cout << (k % n ? k/n+1 : k/n) << '\n';
	}
}
