#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define P pair<ll,ll>
#define FOR(I,A,B) for(ll I = ll(A); I < ll(B); ++I)
#define FORR(I,A,B) for(ll I = ll((B)-1); I >= ll(A); --I)
#define TO(x,t,f) ((x)?(t):(f))
#define SORT(x) (sort(x.begin(),x.end())) // 0 2 2 3 4 5 8 9
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin()) //xi>=v  x is sorted
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin()) //xi>v  x is sorted
#define NUM(x,v) (POSU(x,v)-POSL(x,v))  //x is sorted
#define REV(x) (reverse(x.begin(),x.end())) //reverse
ll gcd_(ll a,ll b){if(a%b==0)return b;return gcd_(b,a%b);}
ll lcm_(ll a,ll b){ll c=gcd_(a,b);return ((a/c)*(b/c)*c);}
#define NEXTP(x) next_permutation(x.begin(),x.end())
const ll INF=ll(1e16)+ll(7);
const ll MOD=1000000007LL;
#define out(a) cout<<fixed<<setprecision((a))
//tie(a,b,c) = make_tuple(10,9,87);
#define pop_(a) __builtin_popcount((a))
ll keta(ll a){ll r=0;while(a){a/=10;r++;}return r;}
ll ketawa(ll a){ll r=0;while(a){r+=a%10;a/=10;}return r;}


template <typename T>
class Lazy_Seg_Tree{
public: // 0-index

	T make_dat_from_buket(T da, T bu, T s){//dat[k] = make_dat_from_buket(dat[k],buket[k],r-l);
		return da + bu;
	}
	T buket_to_child(T ch, T pa){// buket[2*k+1] = buket_to_child(buket[2*k+1],buket[k]);
		return ch + pa;
	}
	T buket_update(T bu , T x , T s){// buket[k] = buket_update(buket[k],x,r-l);
		return bu + x;
	}
	T dat_update(T dc1, T dc2){// dat[k] = dat_update(dat[2*k+1],dat[2*k+2]);
		return min(dc1 , dc2);
	}

  vector<T> dat,buket;
  T initial_d,initial_b,M;
  int n;
  Lazy_Seg_Tree(int n0_=1,T initial_dat=1,T initial_buket=0 ,T M_=1){
    initsize(n0_,initial_dat,initial_buket,M_);
  }
  void initsize(int n0,T initial_da,T initial_bu,T M_){
    M = M_;
    initial_d = initial_da;
    initial_b = initial_bu;
    int k=1;
    while(k<n0)k*=2;
    n=k;
    dat.resize(2*n-1);
    buket.resize(2*n-1);
    for(int i=0;i<2*n-1;i++)dat[i]=initial_da;
    for(int i=0;i<2*n-1;i++)buket[i]=initial_bu;
  }
	
	void eval(int k,int l,int r){
		if(buket[k] != initial_b){
			dat[k] = make_dat_from_buket(dat[k],buket[k],r-l);
			if(r-l>1){
				buket[2*k+1] = buket_to_child(buket[2*k+1],buket[k]);
				buket[2*k+2] = buket_to_child(buket[2*k+2],buket[k]);
			}
			buket[k] = initial_b;
		}
	}

	void operate(int a,int b, T x, int k=0,int l=0, int r=-1){
		if(r<0)r=n;
		eval(k,l,r);
		if(b<=l || r<=a)return;
		if(a<=l && r<=b){
			buket[k] = buket_update(buket[k],x,r-l);
			eval(k,l,r);
		}else{
			operate(a,b,x,2*k+1,l,(l+r)/2);
			operate(a,b,x,2*k+2,(l+r)/2,r);
			dat[k] = dat_update(dat[2*k+1],dat[2*k+2]);
		}
	}
	T get(int a,int b,int k=0,int l=0,int r=-1){
		if(r<0)r=n;
		if(b<=l || r<=a) return initial_d;
		eval(k,l,r);
		if(a<=l && r<=b) return dat[k];
		T vl = get(a,b,2*k+1,l,(l+r)/2);
		T vr = get(a,b,2*k+2,(l+r)/2,r);
		return dat_update(vl,vr);
	}
};



int main(){

	ll n,q;
	cin >> n >> q;
	Lazy_Seg_Tree<ll> sg(n,INF,0,MOD);
	sg.operate(0,n,-INF,0,0,-1);
	FOR(i,0,q){
		ll q_,s,t,x;
		cin >> q_;
		if(q_){
			cin >> s >> t;
			cout << sg.get(s,t+1,0,0,-1) << "\n";
		}else{
			cin >> s >> t >> x;
			sg.operate(s,t+1,x,0,0,-1);
		}
	}


}

