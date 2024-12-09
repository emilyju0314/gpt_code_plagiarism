#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<utility>
#include<vector>
#include<stack>
#include<queue>
#include<cstring>
#include<set>
#include<map>
#define endl "\n"
#define all(v) v.begin(),v.end()
#define st first
#define nd second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long lo;
const int mod=1000000007,N=500005;
lo a,b,c,d,e,f,g=1,h[N];
string s;
vector<lo>v;
 
void solve(){
	cin >> a >> b;
	if(b==1){
		for(lo i=1;i<=a;i++){
			cout << i << ' ';
		}
		cout << endl;
		return;
	}
	h[a+1]=1;
	lo x=1;
	for(lo i=a;i>=1;i--){
		if(b<=x){
			b-=x/2;
			for(lo j=1;j<i;j++) cout << j << ' ';
			lo last=i;
			for(lo j=i+2;j<=a+1;j++){
				if(b<=h[j]){
					for(lo k=j-1;k>=last;k--) cout << k << ' ';
					last=j;
					continue;
				}
				b-=h[j];
			}
			cout << endl;
			return;
		}
		h[i]=x;
		x+=x;
	}
	cout << -1 << endl;
}
 
int main(){
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> g;
	while(g--)solve();
}