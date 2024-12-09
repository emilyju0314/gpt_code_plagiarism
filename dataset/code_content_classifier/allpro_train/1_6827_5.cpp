#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> mp;

#define INF -(1LL<<61)

typedef struct ST{ 
	vector<ll> a;
	int n;
	void init(vector<ll> &b){
		int size= b.size();
		n=1;
		while(n<size) n*=2;
		a =vector<ll> (2*n-1,INF);
		for(int i=0;i<size;i++)	a[i+n-1] = b[i];
		for(int i=n-2;i>=0;i--) a[i] = max(a[i*2+1],a[i*2+2]); //RMQ
	}
	void update(int k,ll val){
		k+=n-1;
		a[k] = val;
		while(k>0){
			k = (k-1)/2;
			a[k] = max(a[k*2+1],a[k*2+2]);//RMQ
		}
	}
	// [aa,b)の最小値
	// kは節点番号l,rはその節点が[l,r)に対応
	// get(aa,b,0,0,n)
	ll get(int aa,int b,int k,int l,int r){
		//[aa,b)に完全に[l,r)が含んでいる場合 この節点
		if(aa<=l && r<=b) return a[k];
		
		//[aa,b)と[l,r)が交差しなければ INF
		if(r<=aa || b<=l) return INF;
		ll vl = get(aa,b,k*2+1,l,(l+r)/2);
		ll vr = get(aa,b,k*2+2,(l+r)/2,r);
		return max(vl,vr);
	}
	ll find(int aa,int b){
		return get(aa,b,0,0,n);
	}	
}ST;



int main(){
	ll n;
	cin>>n;
	vector<mp> c(n);
	ll s = 0;
	for(ll i=0;i<n;i++){
		ll a,b;
		cin>>a>>b;
		c[i] = mp(a,b);
		s += b;
	}
	sort(c.begin(),c.end());
	vector<ll> sum(n,0),u(n,0),l(n,0);
	sum[0] = c[0].second;
	l[0] = c[0].first;
	u[0] = -c[0].first+c[0].second;

	for(ll i= 1;i<n;i++){
		sum[i] = sum[i-1] + c[i].second;
		u[i] = sum[i] - c[i].first;
		l[i] = c[i].first -sum[i-1];
	}
	ST seg;
	seg.init(u);
	 s= 0;
	for(int i=0;i<n;i++){
		s = max(s,l[i]+seg.find(i,n) );
	}

	cout<<s<<endl;



	return 0;
}

