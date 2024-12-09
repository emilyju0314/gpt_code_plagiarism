#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i = 0;i<((ll)(n));i++)
#define reg(i,a,b) for(ll i = ((ll)(a));i<=((ll)(b));i++)
#define irep(i,n) for(ll i = ((ll)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(ll i = ((ll)(b));i>=((ll)(a));i--)
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T = int> void print(vector<T> v){for(auto a:v)cout<<a<<" ";cout<<endl;}

/*
*/

bool ok=true;
ll n,m;
ll visit[100010]={};
pair<ll,ll> p[100010];
V<ll> s,t,v[100010],c[100010];
vector<ll> ans;

// 連結成分に対して全域木から構成
int f(int x, int par_edge){
	int sum=t[x];
	// 行き
	rep(i,v[x].size()){
		ll y = v[x][i];
		if(visit[y]==0){
			visit[y]=visit[x]+1;
			sum += f(y,c[x][i]);
		}
	}
	sum%=2;
	// 帰り　親の辺を切るかどうか
	if(sum==0){
		return 0;
	}else{
		ans.push_back(par_edge);
		return 1;
	}
}

void init(){
	cin>>n>>m;
	rep(i,n){
		ll a,b;
		cin>>a>>b;
		p[i]={a,b};
	}
	p[n]={0,0};  // 番兵
	p[n+1]={1e9+1,0};  // 番兵
	sort(p,p+n+2);
	reg(i,0,n+1){
		s.push_back(p[i].first);
		t.push_back(p[i].second);
	}
	reg(i,0,n){  // 差分化
		if(t[i]!=t[i+1]){
			t[i]=1;
		}else{
			t[i]=0;
		}
	}
	// cerr<<"===S==="<<endl;
	// print(s);
	reg(i,1,m){
		ll l,r;
		cin>>l>>r;
		auto itr = prev(upper_bound(s.begin(), s.end(), r));  // 右端
		auto itl = prev(lower_bound(s.begin(), s.end(), l));  // 左端
		ll ri=itr-s.begin();
		ll li=itl-s.begin();
		// cerr<<li<<","<<ri<<endl;
		if(li>=ri)continue;
		v[ri].push_back(li);
		v[li].push_back(ri);
		c[ri].push_back(i);
		c[li].push_back(i);
	}
}

int main(void){
	init();
	reg(i,0,n){  // 番兵がいるので
		if(visit[i]==0){
			visit[i]=1;
			if(f(i,-1)!=0)ok=false;
		}
	}
	if(ok){
		sort(ans.begin(),ans.end());
		cout<<ans.size()<<endl;
		print(ans);
	}else{
		cout<<-1<<endl;
	}
	return 0;
}