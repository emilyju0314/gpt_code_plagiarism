#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=22;
char s[N][N];
int n, m;
int main(){
	int t, k, m;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0; i<n; ++i){
		scanf("%s",s[i]);
	}
	int ans=0, cnt;
	for(int i=0; i<(1<<n); ++i){
		for(int j=0; j<(1<<m); ++j){
			cnt=0;
			for(int l=0; l<n; ++l){
				for(int d=0; d<m; ++d){
					if(!((1<<l)&i)&&!((1<<d)&j)){
						if(s[l][d]=='#'){
							++cnt;
						}
					}
				}
			}
			if(cnt==k)++ans;
		}
	}
	cout<<ans<<endl;
}