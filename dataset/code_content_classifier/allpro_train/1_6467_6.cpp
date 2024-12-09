#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define perl(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define pb push_back
#define ins insert
#define pqueue(x) priority_queue<x,vector<x>,greater<x>>
#define all(x) (x).begin(),(x).end()
#define CST(x) cout<<fixed<<setprecision(x)
#define vtpl(x,y,z) vector<tuple<x,y,z>>
#define rev(x) reverse(x);
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using pl=pair<ll,ll>;
using vpl=vector<pl>;
using vvpl=vector<vpl>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9+10;
const ll INF=4e18;
const ll dy[8]={1,0,-1,0,1,1,-1,-1};
const ll dx[8]={0,-1,0,1,1,-1,1,-1};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

class SuffixArray{
    using vi=vector<int>;
    vi sa_is(const vi &str,const int k){
        const int n=str.size();
        vector<bool> isS(n),isLMS(n);
        vi LMSs;
        isS[n-1]=true;
        for(int i=n-2;i>=0;i--){
            isS[i]=str[i]<str[i+1]||(str[i]==str[i+1]&&isS[i+1]);
        }
        rep(i,n){
            if(isS[i]&(i==0||!isS[i-1])){
                isLMS[i]=true;LMSs.push_back(i);
            }
        }
        vi pseudo_sa=induced_sort(str,LMSs,isS,k);
        vi orderedLMSs(LMSs.size());
        int index=0;
        for(int x:pseudo_sa){
            if(isLMS[x])orderedLMSs[index++]=x;
        }
        pseudo_sa[orderedLMSs[0]]=0;
        int rank=0;
        if(orderedLMSs.size()>1)pseudo_sa[orderedLMSs[1]]=++rank;
        repl(i,1,orderedLMSs.size()-1){
            bool isdiff=false;
            rep(j,n){
                int p=orderedLMSs[i]+j;
                int q=orderedLMSs[i+1]+j;
                if(str[p]!=str[q]||isLMS[p]!=isLMS[q]){
                    isdiff=true;break;
                }
                if(j>0&&isLMS[p])break;
            }
            pseudo_sa[orderedLMSs[i+1]]=isdiff? ++rank:rank;
        }
        vi newstr(LMSs.size());
        index=0;
        rep(i,n){
            if(isLMS[i])newstr[index++]=pseudo_sa[i];
        }
        vi LMS_sa;
        if(rank+1==LMSs.size())LMS_sa=orderedLMSs;
        else {
            LMS_sa=sa_is(newstr,rank+1);
            for(auto& x:LMS_sa)x=LMSs[x];
        }
        return induced_sort(str,LMS_sa,isS,k);
    }

    vi induced_sort(const vi& str,const vi& LMSs,const vector<bool>& isS,const int k){
        int n=str.size();
        vi buckets(n);
        vi chars(k+1);
        for(auto c:str)chars[c+1]++;
        rep(i,k)chars[i+1]+=chars[i];
        vi count(k);
        for(int i=LMSs.size()-1;i>=0;i--){
            int c=str[LMSs[i]];
            buckets[chars[c+1]-1-count[c]++]=LMSs[i];
        }
        count=vi(k);
        rep(i,n){
            if(buckets[i]==0||isS[buckets[i]-1])continue;
            int c=str[buckets[i]-1];
            buckets[chars[c]+count[c]++]=buckets[i]-1;
        }
        count=vi(k);
        for(int i=n-1;i>=0;i--){
            if(buckets[i]==0||!isS[buckets[i]-1])continue;
            int c=str[buckets[i]-1];
            buckets[chars[c+1]-1-count[c]++]=buckets[i]-1;
        }
        return buckets;
    }
    public:
    string S; int N;
    vi sa,lcp;
    SuffixArray(string s):S(s),N(s.size()){
        S+="$";
        vi str(N+1);
        rep(i,N+1) str[i]=S[i]-'$';
        sa=sa_is(str,128);
        sa.erase(sa.begin());
    }
    bool search(string t){
        int l=0,r=N;
        while(r-l>1){
            int mid=(l+r)/2;
            if(S.substr(sa[mid],t.size())<=t)l=mid;
            else r=mid;
        }
        return S.substr(sa[l],t.size())==t;
    }
    void construct_lcp(){
        lcp=vi(N+1,0);
        vi ssa(N+1);ssa[0]=N;rep(i,N)ssa[i+1]=sa[i];
        vi rank(N+1);
        rep(i,N+1)rank[ssa[i]]=i;
        int h=0;lcp[0]=0;
        rep(i,N){
            int j=ssa[rank[i]-1];
            if(h>0)h--;
            for(;j+h<N&&i+h<N;h++){
                if(S[j+h]!=S[i+h])break;
            }
            lcp[rank[i]-1]=h;
        }
    }
};

int main(){
    string s;cin >> s;
    SuffixArray x(s);
    x.construct_lcp();
    ll ans=1LL*s.size()*(s.size()+1)/2;
    rep(i,s.size()){
        ans-=x.lcp[i];
    }
    cout << ans <<endl;
}