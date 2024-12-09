#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <climits>

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

const int INF=100000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
using namespace std;
typedef pair<int ,int > P;
typedef long long ll;


char next(char c) {
    if(c=='z') return 'a';
    return c+1;
}
char next(char c,int n) {
    rep(i,n) c=next(c);
    return c;
}
int n;
void solve() {
    string s;
    cin>>s;
    vector<int> a,b;
    rep(i,n) {
        int s,t;
        cin>>s>>t;
        s--,t--;
        a.pb(s);
        b.pb(t);
    }

    reverse(all(a));
    reverse(all(b));

    rep(i,n) {
        int d=abs(a[i]-b[i]);
        s[a[i]]=next(s[a[i]],d);
        s[b[i]]=next(s[b[i]],d);
        swap(s[a[i]],s[b[i]]);
    }
    cout<<s<<endl;
}
int main() {
    while(cin>>n) {
        if(n==0) break;
        solve();
    }
    return 0;
}