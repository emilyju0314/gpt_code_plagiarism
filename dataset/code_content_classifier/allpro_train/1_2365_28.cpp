#include <bits/stdc++.h>

using namespace std;
 
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define t_times int t; cin >> t; while(t--)
#define fr(i, st, n) for(int i = (int )st; i < (int )n; i++)
#define rfr(i, en, st) for(int i = (int )en; i >= (int )st; i--)
#define all(c) (c).begin(), (c).end()
#define fi first
#define se second
#define pb push_back
#define sz(a) (int)((a).size())
 
typedef long long int LL;
typedef pair< int, int> ii;
typedef vector< int> vi;
typedef vector< ii> vii;
typedef vector< vi> vvi;

template<typename T,typename U>
ostream& operator<<(ostream& out,const pair<T,U>& p){
	out<<"{" <<p.fi<<","<<p.se<<"}";
	return out;
}
template<typename T>
ostream& operator<<(ostream& out,const std::vector<T>& v){
	for(auto& x:v)out<<x<<" ";
	return out;
}

const int mod = 1e9 + 7;
const LL INF = 9e18 + 2e17;
const int inf = 2e9;
const double eps = 1e-10;

const int N=1e6+7;
// vvi pos;

void solve() {
	vi cnttt;
	cnttt=vi(N/1000,0);
	// pos =vvi(N,vi());
	int n;cin>>n;
	vi a(2*n);
	unordered_map<int,int>cntt,cntt_o;
	fr(i,0,2*n){
		cin>>a[i];
		cntt[a[i]]++;
		cntt_o[a[i]]++;
	}

	sort(all(a));
	fr(i,0,2*n-1){
		cntt.clear();
		fr(i,0,2*n)cntt[a[i]]++;
		cntt=cntt_o;
		int initial=a[i]+a[2*n-1];
		int last=a[2*n-1];
		cntt[last]--;
		cntt[a[i]]--;
		bool ok=true;
		vii ans;
		ans.pb({last,a[i]});

		rfr(j,2*n-2,0){
			if(cntt[a[j]]==0)continue;
			cntt[a[j]]--;
			int other=last-a[j];
			// cout<<"las ot "<<last<<" "<<other<<endl;
			if(cntt.count(other)&&cntt[other]>0){
				cntt[other]--;
				last=a[j];
				ans.pb({last,other});
			}else{
				cntt[a[j]]++;
				ok=false;
				for(auto x:ans){
					cntt[x.fi]++;
					cntt[x.se]++;
				}
				// for(int i = 1;i<15;i++)cout<<cntt[i]<<" ";
				// 	cout<<endl;
				break;
			}
		}

		if(ok){
			cout<<"YES\n";
			cout<<initial<<endl;
			for(auto x:ans)cout<<x.fi<<" "<<x.se<<endl;
			return;
		}

	}
	cout<<"NO\n";

}

int main(int argc, char const *argv[])
{
	fastio;
	
	t_times{
	solve();
	}


	return 0;
}


/*

learnings

vector initialisation takes O(n) time
map copy is bad too


*/