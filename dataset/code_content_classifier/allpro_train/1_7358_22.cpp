#include<bits/stdc++.h>
using namespace std;
using Int = long long;

struct SuffixArray{
  Int n,k;
  string S;
  vector<Int> sa,lcp;
  SuffixArray(){}
  SuffixArray(string& S):S(S){init();}
  void init(){
    n=S.length();
    S.push_back('$');
    build_sa();
  }
  void build_sa(){
    sa.clear();
    sa.resize(n+1,0);
    iota(sa.begin(),sa.end(),0);
    sort(sa.begin(),sa.end(),
	 [&](Int a,Int b){
	   if(S[a]==S[b]) return a>b;
	   return S[a]<S[b];
	 });
    vector<Int> c(n+1,0),r(n+1),cnt(n+1),s(n+1);
    for(Int i=0;i<=n;i++) r[i]=S[i];
    for(Int len=1;len<=n;len*=2){
      for(Int i=0;i<=n;i++){
	 c[sa[i]]=
	   i>0 &&
	   r[sa[i-1]]==r[sa[i]] &&
	   sa[i-1]+len<=n &&
	   r[sa[i-1]+len/2]==r[sa[i]+len/2] ?
	   c[sa[i-1]]:i;
      }
      iota(cnt.begin(),cnt.end(),0);
      copy(sa.begin(),sa.end(),r.begin());
      for(Int i=0;i<=n;i++){
	Int s1=r[i]-len;
	if(s1>=0) sa[cnt[c[s1]]++]=s1;
      }
      c.swap(r);
    }
  }
};

//INSERT ABOVE HERE
signed main(){
  Int n,k;
  string s;
  cin>>n>>k>>s;
  auto calc=[](Int x){return x*(x+1)/2;};
  Int zs=0;
  vector<Int> cnt(n+1,1);
  for(Int i=0;i<n;i++){
    if(s[i]=='0'){
      if(i+1>=n||s[i+1]!='0') zs+=calc(cnt[i]);
      if(i+1<n) cnt[i+1]+=cnt[i];
      cnt[i]=0;
    }
  }
  if(k<=zs){
    cout<<0<<endl;
    return 0;
  }
  k-=zs+1;
  vector<Int> sum(n+1,0);
  for(Int i=0;i<n;i++) sum[i+1]=sum[i]+cnt[i];
  Int len=1;
  while(k>=sum[n+1-len]&&len<n) k-=sum[n+1-(len++)];
  SuffixArray sa(s);
  Int pos=0;
  for(Int i=1;i<=n;i++){
    if(s[sa.sa[i]]=='0'||sa.sa[i]+len>n) continue;
    //cout<<len<<" "<<i<<" "<<k<<endl;
    if(k>=0) pos=sa.sa[i];
    k-=cnt[sa.sa[i]];
  }
  cout<<s.substr(pos,len)<<endl;
  return 0;
}

