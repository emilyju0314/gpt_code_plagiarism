#include <bits/stdc++.h>
using namespace std;

#define dump(...) cout<<"# "<<#__VA_ARGS__<<'='<<(__VA_ARGS__)<<endl
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define peri(i,a,b) for(int i=int(b);i-->int(a);)
#define rep(i,n) repi(i,0,n)
#define per(i,n) peri(i,0,n)
#define all(c) begin(c),end(c)
#define mp make_pair
#define mt make_tuple

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<string> vs;

template<typename T1,typename T2>
ostream& operator<<(ostream& os,const pair<T1,T2>& p){
	return os<<'('<<p.first<<','<<p.second<<')';
}

template<typename Tuple>
void print_tuple(ostream&,const Tuple&){}
template<typename Car,typename... Cdr,typename Tuple>
void print_tuple(ostream& os,const Tuple& t){
	print_tuple<Cdr...>(os,t);
	os<<(sizeof...(Cdr)?",":"")<<get<sizeof...(Cdr)>(t);
}
template<typename... Args>
ostream& operator<<(ostream& os,const tuple<Args...>& t){
	print_tuple<Args...>(os<<'(',t);
	return os<<')';
}

template<typename Ch,typename Tr,typename C>
basic_ostream<Ch,Tr>& operator<<(basic_ostream<Ch,Tr>& os,const C& c){
	os<<'[';
	for(auto i=begin(c);i!=end(c);++i)
		os<<(i==begin(c)?"":" ")<<*i;
	return os<<']';
}

constexpr int INF=1e9;
constexpr int MOD=1e9+7;
constexpr double EPS=1e-9;

template<typename T,template<typename>class Compare>
struct Queue{
	Compare<T> Comp;
	deque<T> a1,a2,b1,b2;
	void Push(int x){
		a2.push_back(x);
		while(b2.size() && Comp(x,b2.back())) b2.pop_back();
		b2.push_back(x);
		if(a1.size()<a2.size()){
			int y=a2.front();
			a1.push_back(y);
			if(b1.empty() || Comp(y,b1.back())) b1.push_back(y);
			a2.pop_front();
			if(b2.size() && b2.front()==y) b2.pop_front();
		}
	}
	int Pop(){
		int x=a1.back();
		a1.pop_back();
		if(b1.size() && x==b1.back()) b1.pop_back();
		if(a1.size()<a2.size()){
			int y=a2.front();
			a1.push_back(y);
			if(b1.empty() || Comp(y,b1.back())) b1.push_back(y);
			a2.pop_front();
			if(b2.size() && b2.front()==y) b2.pop_front();
		}
		return x;
	}
	int PriorLeft(){
		return KthLeft(0);
	}
	int PriorRight(){
		return KthRight(0);
	}
	int KthLeft(int k){
		return b1[b1.size()-1-k];
	}
	int KthRight(int k){
		return b2[k];
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	constexpr char endl='\n';
	
	for(int q;cin>>q && q;){
		Queue<int,less> qmin;
		Queue<int,greater> qmax;
		rep(_,q){
			int t; cin>>t;
			if(t==0){ // push
				int x; cin>>x;
				qmin.Push(x),qmax.Push(x);
			}
			if(t==1) // del
				cout<<(qmin.Pop(),qmax.Pop())<<endl;
			if(t==2) // minl
				cout<<qmin.PriorLeft()<<endl;
			if(t==3) // minr
				cout<<qmin.PriorRight()<<endl;
			if(t==4){ // minl kth
				int k; cin>>k;
				cout<<qmin.KthLeft(k-1)<<endl;
			}
			if(t==5){ // maxl kth
				int k; cin>>k;
				cout<<qmin.KthRight(k-1)<<endl;
			}
			if(t==6) // maxl
				cout<<qmax.PriorLeft()<<endl;
			if(t==7) // maxr
				cout<<qmax.PriorRight()<<endl;
			if(t==8){ // maxl kth
				int k; cin>>k;
				cout<<qmax.KthLeft(k-1)<<endl;
			}
			if(t==9){ // maxr kth
				int k; cin>>k;
				cout<<qmax.KthRight(k-1)<<endl;
			}
		}
		cout<<"end"<<endl;
	}
}