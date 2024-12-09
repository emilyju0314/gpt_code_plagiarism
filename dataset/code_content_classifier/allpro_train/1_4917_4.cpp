#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <queue>
#include <stack>
#include <functional>
#include <utility>
#include <complex>
#include <bitset>
#include <numeric>
#include <random>
using namespace std;

#define REP(i,n) for(int (i)=0; (i)<(n) ;++(i))
#define REPN(i,a,n) FOR((i),(a),(a)+(n))
#define FOR(i,a,b) for(int (i)=(a); (i)<(b) ;++(i))
#define PB push_back
#define MP make_pair
#define SE second
#define FI first
#define DBG(a) cerr<<(a)<<endl;
#define ALL(v) (v).begin(),(v).end()
typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
const LL LINF=334ll<<53; const int INF=15<<26; const LL MOD=1E9+7;
bool comp (pair<int,int> a, pair<int,int>b){
    return a.FI+a.SE<b.FI+b.SE or (a.FI+a.SE==b.FI+b.SE and a.FI<b.FI);
}
int cnt(multiset<pair<int,int>> &s, int a, int b){
    return s.count(make_pair(a,b));
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<int,int>> d;
    multiset<pair<int,int>> s;
    REP(i,n){
        int a,b;
        cin >> a>>b;
        s.insert(make_pair(a,b));
        d.push_back(make_pair(a,b));
    }
    if(d[0].FI!=0 or d[1].SE!=0 or d[1].FI!=d[0].SE or d[0].SE==0){
        cout << -1 << endl; return 0;
    }
    FOR(i,2,n){
        if(d[i].FI==0 or d[i].SE==0){
            cout << -1 << endl; return 0;
        }
    }
    FOR(i,1,d[0].SE){
        if(cnt(s,i,d[0].SE-i)==0){
            cout << -1 << endl; return 0;
        }
    }
    //0~1
    int ans=cnt(s,1,d[0].SE-1);

    FOR(i,1,d[0].SE){
        ans+=max(cnt(s,i,d[0].SE-i),cnt(s,i+1,d[0].SE-i-1));
    }
    sort(d.begin(),d.end());
    d.erase(unique(ALL(d)),d.end());
    sort(d.begin(),d.end(),comp);
    int v=0;
    for(auto it=lower_bound(ALL(d),make_pair(1,d[0].SE),comp); it<d.end();it++){
        int d0=it->FI,d1=it->SE,add=0,now=cnt(s,d0,d1);

        if(v){
            if(cnt(s,d0-1,d1-1)&&cnt(s,d0+1,d1-1)){
                add=max(v,now);
                v=min(v,now);
            }else if(cnt(s,d0-1,d1-1)){
                add=v+now;
                v=0;
            }else if(cnt(s,d0+1,d1-1)){
                add=max(v,now);
                v=now;
            }else if(cnt(s,d0,d1-1)){
                add=max(v,now)+now;
                v=0;
            }else {
                cout << -1 << endl; return 0;
            }
        }else if(cnt(s,d0-1,d1-1)){
            add=now;
        }else if(cnt(s,d0-1,d1)or cnt(s,d0-1,d1+1)){
            add=now;
            if(cnt(s,d0+1,d1-1)){
                v=add;
            }else if(cnt(s,d0,d1-1)){
                add*=2;
            }else{
                cout << -1 << endl; return 0;
            }
        }else{
            cout << -1 << endl; return 0;
        }
        ans+=add;
    }

    cout << ans <<endl;
    return 0;
}
