#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
#define eprintf(...) fprintf(stderr,__VA_ARGS__)

ll n;
int m,idx;
vector<int> a;

int main(){
	scanf("%lld", &n);
	ll nn = n;
	n++;
	for(int j = 40; j >= 0; j--){
		if (n >> (j + 1)) {
			++idx;
			a.insert(a.begin() + a.size() / 2, idx);
			a.push_back(idx);
		}
		if ((n >> j) != 1 && (n >> j &1)) {
			++idx;
			a.insert(a.begin(), idx);
			a.push_back(idx);
		}
	}
	printf("%d\n",a.size());
	for(int i=0; i<int(a.size()); i++) printf("%d%c", a[i], " \n"[i + 1 == a.size()]);
}