#include<bits/stdc++.h>
using namespace std;
using Int = long long;

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


struct Precision{
  Precision(){
    cout<<fixed<<setprecision(12);
  }
}precision_beet;

//INSERT ABOVE HERE
signed main(){
  auto calc=[](vector<Int> v){
    Int n=v.size();
    const double PI = acos(-1);
    double res=0;
    sort(v.begin(),v.end());
    do{      
      v.emplace_back(v[0]);
      auto calc2=[&](double x){
	double res=0,tmp=0;
	Int p=0;
	for(Int i=0;i<n;i++)
	  if(v[p]*v[p+1]>v[i]*v[i+1]) p=i;
	for(Int i=0;i<n;i++){
	  double y=acos(v[p]*v[p+1]*cos(x)/(v[i]*v[i+1]));
	  res+=y;
	  tmp+=v[i]*v[i+1]*sin(y)/2;
	}
	return make_pair(res,tmp);
      };
      double l=0,r=PI;
      for(Int i=0;i<100;i++){
	double m=(l+r)/2;
	if(calc2(m).first<=2*PI) l=m;
	else r=m;
      }
      const double EPS = 1e-6;
      if(abs(2*PI-calc2(l).first)<EPS)
	chmax(res,calc2(l).second);
      v.pop_back();
    }while(next_permutation(v.begin(),v.end()));
    return res;
  };
  
  Int n;
  cin>>n;
  vector<Int> r(n);
  for(Int i=0;i<n;i++) cin>>r[i];
  double ans=0;
  for(Int b=1;b<(1<<n);b++){
    vector<Int> v;
    for(Int i=0;i<n;i++)
      if((b>>i)&1) v.emplace_back(r[i]);
    if(v.size()<3u) continue;
    chmax(ans,calc(v));
  }
  cout<<ans<<endl;
  return 0;
}

