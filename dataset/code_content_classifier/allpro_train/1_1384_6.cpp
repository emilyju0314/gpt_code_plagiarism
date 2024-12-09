#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T>
vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T>
vector<vector<T> > make_v(size_t a,size_t b){
  return vector<vector<T> >(a,make_v<T>(b));
}
template<typename T>
vector<vector<vector<T> > > make_v(size_t a,size_t b,size_t c){
  return vector<vector<vector<T> > > (a,make_v<T>(b,c));
}

template<typename T,typename V>
typename enable_if<is_class<T>::value==0>::type
fill_v(T &t,const V &v){t=v;}

template<typename T,typename V>
typename enable_if<is_class<T>::value!=0>::type
fill_v(T &t,const V &v){
  for(auto &e:t) fill_v(e,v);
}

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
struct Precision{
  Precision(){
    cout<<fixed<<setprecision(20);
  }
}precision_beet;

signed main(){  
  cin.tie(0);
  ios::sync_with_stdio(0);
  Int n,k;
  while(cin>>n>>k,n){
    using T = tuple<Int, Int, Int>;
    vector<T> v;
    map<Int, Int> cnt;
    for(Int i=0;i<n;i++){
      Int x,y,z;
      cin>>x>>y>>z;
      v.emplace_back(z,x,y);
      cnt[z]++;
    }
    sort(v.rbegin(),v.rend());
    v.erase(unique(v.begin(),v.end()),v.end());
    assert((Int)v.size()==n);
    
    const double inf = 1e18;
    auto dist=make_v<double>(n,n);
    fill_v(dist,0);
    auto calc=[&](T a,T b){
      if(get<0>(a)==get<0>(b)) return inf;
      double sum=0;
      sum+=(get<0>(a)-get<0>(b))*(get<0>(a)-get<0>(b));
      sum+=(get<1>(a)-get<1>(b))*(get<1>(a)-get<1>(b));
      sum+=(get<2>(a)-get<2>(b))*(get<2>(a)-get<2>(b));
      return sqrt(sum);
    };
    
    for(Int i=0;i<n;i++)
      for(Int j=0;j<n;j++)
	dist[i][j]=calc(v[i],v[j]);

    auto di=[&](Int i,Int j){
      if(min(i,j)<0) return (double)0.;
      return dist[i][j];
    };

    auto dp=make_v<double>(n+1,n+1,n+1);
    fill_v(dp,inf);
    dp[0][0][0]=0;
    
    auto nx=make_v<double>(n+1,n+1,n+1);    
    for(Int i=0;i<n;i++){
      fill_v(nx,inf);
      for(Int a=-1;a<i;a++){
	for(Int b=-1;b<0||b<a;b++){
	  for(Int c=-1;c<0||c<b;c++){
	    if(dp[a+1][b+1][c+1]>=inf) continue;
	    //cout<<i-1<<" "<<a<<" "<<b<<" "<<c<<":"<<dp[a+1][b+1][c+1]<<endl;
	    chmin(nx[a+1][b+1][c+1],dp[a+1][b+1][c+1]+di(i-1,i));
	    chmin(nx[i+0][b+1][c+1],dp[a+1][b+1][c+1]+di(a,i));
	    chmin(nx[i+0][a+1][c+1],dp[a+1][b+1][c+1]+di(b,i));
	    chmin(nx[i+0][a+1][b+1],dp[a+1][b+1][c+1]+di(c,i));
	  }
	}
      }
      swap(dp,nx);
    }
    double ans=inf;
    
    for(Int a=-1;a<n;a++){
      for(Int b=-1;b<0||b<a;b++){
	for(Int c=-1;c<0||c<b;c++){
	  Int s=(a==-1)+(b==-1)+(c==-1);
	  if(k+s>=4) chmin(ans,dp[a+1][b+1][c+1]);
	}
      }
    }
    if(ans>inf/2) cout<<-1<<endl; 
    else cout<<ans<<endl;
  }
  return 0;
}

