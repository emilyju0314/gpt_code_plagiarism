
#include<bits/stdc++.h>
#define dd(x) cout << #x << " = " << x << ", "
#define de(x) cout << #x << " = " << x << endl
 
using namespace std;
 
const int maxn=107;
vector<pair<int, pair<int,int>>> v;
int cnt[maxn];
int main()
{
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int T;
	cin>>T;
	for(int t=0;t<T;t++){
		int n,m;
		cin>>n>>m;
		v.clear();	
		memset(cnt,0,n*sizeof(int));
		vector<vector<int>> a(n,vector<int>(m));
		for(int i=0;i<n;i++)for(int j=0;j<m;j++){
			cin>>a[i][j];
			v.push_back( {a[i][j], {i,j}} );
		}
		// for(int i=0;i<n;i++)for(int j=0;j<m;j++){
		// 	cout<<a[i][j]<<(j==m-1?'\n':' ');
		// }
		// cout<<endl;
		sort(v.begin(),v.end());
		for(int i=0;i<m;i++){
			cnt[v[i].second.first]++;
		}
		// for(int i=0;i<n;i++)for(int j=0;j<m;j++){
		// 	cout<<a[i][j]<<(j==m-1?'\n':' ');
		// }
		int pre=0;
		for(int i=0;i<n;i++){
			sort(a[i].begin(),a[i].end());
			// de(pre);
  			rotate(a[i].begin(),a[i].end()-pre,a[i].end());
  			pre+=cnt[i];
		}
		for(int i=0;i<n;i++)for(int j=0;j<m;j++){
			cout<<a[i][j]<<(j==m-1?'\n':' ');
		}
	}
	return 0;
}