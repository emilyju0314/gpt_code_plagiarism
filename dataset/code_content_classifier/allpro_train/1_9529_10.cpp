#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

struct SuffixArray{
  string s;
  vector<Int> sa,rev;

  SuffixArray(){}
  SuffixArray(const string &S):s(S){
    Int n=s.size();
    s.push_back('$');
    sa.resize(n+1);
    iota(sa.begin(),sa.end(),0);
    sort(sa.begin(),sa.end(),
         [&](Int a,Int b){
           if(s[a]==s[b]) return a>b;
           return s[a]<s[b];
         });
    vector<Int> c(n+1,0),r(n+1),cnt(n+1);
    for(Int i=0;i<=n;i++) r[i]=s[i];
    for(Int len=1;len<=n;len*=2){
      for(Int i=0;i<=n;i++){
        c[sa[i]]=i;
        if(i>0 &&
           r[sa[i-1]]==r[sa[i]] &&
           sa[i-1]+len<=n &&
           r[sa[i-1]+len/2]==r[sa[i]+len/2]) c[sa[i]]=c[sa[i-1]];
      }
      iota(cnt.begin(),cnt.end(),0);
      copy(sa.begin(),sa.end(),r.begin());
      for(Int i=0;i<=n;i++){
        Int s1=r[i]-len;
        if(s1>=0) sa[cnt[c[s1]]++]=s1;
      }
      c.swap(r);
    }
    rev.resize(n+1);
    for(Int i=0;i<=n;i++) rev[sa[i]]=i;
  }
  Int operator[](Int i) const{return sa[i];}

  bool lt_substr(string &t,Int si,Int ti){
    Int sn=s.size(),tn=t.size();
    while(si<sn&&ti<tn){
      if(s[si]<t[ti]) return 1;
      if(s[si]>t[ti]) return 0;
      si++;ti++;
    }
    return si==sn&&ti<tn;
  }

  Int lower_bound(string& t){
    Int l=0,r=s.size();
    while(l+1<r){
      Int m=(l+r)>>1;
      if(lt_substr(t,sa[m],0)) l=m;
      else r=m;
    }
    return r;
  }

  Int upper_bound(string& t){
    t.back()++;
    Int res=lower_bound(t);
    t.back()--;
    return res;
  }

  // O(|T|*log|S|)
  Int count(string& T){
    return upper_bound(T)-lower_bound(T);
  }
};
struct LongestCommonPrefix{
  SuffixArray sa;

  vector<Int> lcp,ht;
  vector<vector<Int> > dat;
  LongestCommonPrefix(string &s):sa(s){
    Int n=s.size();
    lcp.assign(n,0);

    Int t=0;
    lcp[0]=0;
    for(Int i=0;i<n;i++){
      Int j=sa[sa.rev[i]-1];
      if(t>0) t--;
      for(;j+t<n&&i+t<n;t++){
        if(sa.s[j+t]!=sa.s[i+t]) break;
      }
      lcp[sa.rev[i]-1]=t;
    }

    Int h=1;
    while((1<<h)<n) h++;
    dat.assign(h,vector<Int>(n));
    ht.assign(n+1,0);
    for(Int j=2;j<=n;j++) ht[j]=ht[j>>1]+1;

    for(Int j=0;j<n;j++) dat[0][j]=lcp[j];
    for(Int i=1,p=1;i<h;i++,p<<=1)
      for(Int j=0;j<n;j++)
        dat[i][j]=min(dat[i-1][j],dat[i-1][min(j+p,n-1)]);
  }

  Int query(Int a,Int b){
    //a=sa.rev[a];b=sa.rev[b];
    if(a>b) swap(a,b);
    Int l=b-a;
    return min(dat[ht[l]][a],dat[ht[l]][b-(1<<ht[l])]);
  }
};


template <typename E>
struct SegmentTree{
  using H = function<E(E,E)>;
  Int n,height;
  H h;
  E ei;
  vector<E> laz;
  SegmentTree(H h,E ei):h(h),ei(ei){}
  void init(Int n_){
    n=1;height=0;
    while(n<n_) n<<=1,height++;
    laz.assign(2*n,ei);
  }
  inline void eval(Int k){
    if(laz[k]==ei) return;
    laz[(k<<1)|0]=h(laz[(k<<1)|0],laz[k]);
    laz[(k<<1)|1]=h(laz[(k<<1)|1],laz[k]);
    laz[k]=ei;
  }
  inline void thrust(Int k){
    for(Int i=height;i;i--) eval(k>>i);
  }
  void update(Int a,Int b,E x){
    thrust(a+=n);
    thrust(b+=n-1);
    for(Int l=a,r=b+1;l<r;l>>=1,r>>=1){
      if(l&1) laz[l]=h(laz[l],x),l++;
      if(r&1) --r,laz[r]=h(laz[r],x);
    }
  }
  E get_val(Int a){
    thrust(a+=n);
    return laz[a];
  }
  void set_val(Int a,E x){
    thrust(a+=n);
    laz[a]=x;
  }
};

//INSERT ABOVE HERE
signed main(){
  string s,t;
  cin>>s>>t;

  string b=s+'%'+t;
  LongestCommonPrefix lcp(b);

  Int n=s.size(),m=t.size();
  const Int DEBUG = 0;

  set<Int> ss;
  for(Int i=0;i<=n+1+m;i++){
    if(DEBUG) cout<<i<<":"<<b.substr(lcp.sa[i])<<endl;
    if(!isalpha(b[lcp.sa[i]])) continue;
    if(n<lcp.sa[i]) ss.emplace(i);
  }

  vector<Int> nx(n+1,-1);
  for(Int i=0;i<=n+1+m;i++){
    if(!isalpha(b[lcp.sa[i]])) continue;
    Int k=lcp.sa[i];
    if(k>=n) continue;

    //cout<<i<<" "<<k<<":";
    auto it=ss.upper_bound(i);
    if(it!=ss.end()) chmax(nx[k],lcp.query(i,*it));

    //if(it!=ss.end()) cout<<*it<<" "<<lcp.query(i,*it)<<":::";

    if(it!=ss.begin()) it--;
    if(it!=ss.end()) chmax(nx[k],lcp.query(i,*it));

    //if(it!=ss.end()) cout<<*it<<" "<<lcp.query(i,*it)<<":::";
    //cout<<endl;
  }

  if(DEBUG)
    for(Int i=0;i<n;i++) cout<<i<<":"<<nx[i]<<endl;

  Int len;
  cin>>len;

  auto h=[&](Int a,Int b){return a||b;};
  Int ei=0;
  SegmentTree<Int> seg(h,ei);
  seg.init(n+m+1000);

  seg.set_val(0,1);
  for(Int i=0;i<n;i++){
    if(!seg.get_val(i)) continue;
    if(nx[i]<len) continue;
    Int nl=i+len;
    Int nr=i+nx[i]+1;
    seg.update(nl,nr,1);
  }

  cout<<(seg.get_val(n)?"Yes":"No")<<endl;
  return 0;
}

