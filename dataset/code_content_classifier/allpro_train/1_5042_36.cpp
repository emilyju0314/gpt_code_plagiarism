#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i = 0; i<n; i++)
#define sz(v) (int)(v.size())
#define prin(a) cout << #a << " = " << a << endl
#define prinv(v) cout << #v << " = "; for(auto it : v) cout << it << ", "; cout << endl
#define all(v) (v).begin(),(v).end()

typedef long long ll;

#define rmin(a,b) a = min<ll>(a,b)
#define rmax(a,b) a = max<ll>(a,b)

#define fi first
#define se second

const int N = 2e5+10;
vector<int> mat[N];

ll n;
vector<int> v[N];
int tem[N];

int r;

bool check(int i, int id){
	int qnt = 0;
	for(auto &val : v[i]) if(tem[val]==id){
		qnt++;
		if(qnt==2) return 1;
	}
	return 0;
}

bool checar(int is, int a, int b){
	if(a>b) swap(a,b);
	
	int x = a;
	for(auto &val : v[is]){
		if(val==x){
			if(x==b) return 1;
			x = b;
		}
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	int id = 1;
	
	fr(tt,t){
		
		int soma = 0;
		map<int,int> mpr;
		cin >> n;
		fr(i,n){
			int tam; cin >> tam;
			soma+=tam;
			v[i].resize(tam);
			fr(j,tam){
				cin >> v[i][j];
				mpr[v[i][j]];
			}
		}
		int maxv = -1;
		{
			{
				int i = -1;
				for(auto &[a,b] : mpr){
					i++;
					b = i;
					maxv = i;
				}
			}
			fr(i,n) fr(j,sz(v[i])) v[i][j] = mpr[v[i][j]];
			fr(i,n) sort(all(v[i]));
			mpr.clear();
		}
		
		r = sqrt(soma);
		r = max<ll>(r,1);
		//if(r>30) r = 15*r/30;
		
		int i1_ans = -1, i2_ans = -1;
		
		
		fr(is,n){
			if(i1_ans!=-1) break;
			if(sz(v[is])>r){
				for(auto &val : v[is]) tem[val] = id;
				id++;
				fr(j,n){
					if(is==j) continue;
					if(j>is and sz(v[j])>r) continue;
					if(check(j,id-1)){
						i1_ans = is, i2_ans = j;
						break;
					}
				}
			} else{
				fr(i,sz(v[is])){
					for(int j = i+1; j<sz(v[is]); j++){
						mat[v[is][i]].push_back(v[is][j]);
					}
				}
			}
		}
		
		if(i1_ans==-1){
			int v1 = -1, v2 = -1;
			fr(i,maxv+1){
				for(auto &val : mat[i]){
					if(tem[val]==id){
						v1 = i, v2 = val;
						break;
					}
					tem[val] = id;
				}
				id++;
				if(v1!=-1) break;
			}
			if(v1!=-1){
				fr(i,n) if(sz(v[i])<=r){
					if(checar(i,v1,v2)){
						if(i1_ans==-1) i1_ans = i;
						else{
							i2_ans = i;
							break;
						}
					}
				}
				assert(i2_ans!=-1);
			}
		}
		
		if(i1_ans!=-1){
			if(i1_ans>i2_ans) swap(i1_ans,i2_ans);
			cout << i1_ans+1 << " " << i2_ans+1 << "\n";
		} else{
			cout << "-1\n";
		}
		
		fr(i,n) v[i].clear();
		fr(i,maxv+1) mat[i].clear();
	}
}
