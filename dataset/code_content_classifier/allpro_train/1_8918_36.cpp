#include <iostream>
#include <fstream>
#include <algorithm>
//#define LOCAL
using namespace std;
typedef long long ll;
const int mx=1e3+10;
ll num[mx];


int main() {
#ifdef LOCAL
ifstream fin("1.txt");
streambuf*p;
p=cin.rdbuf(fin.rdbuf());
#endif // LOCAL
ll n;
cin>>n;
for(ll i=0;i<n;i++) cin>>num[i];
ll qn;
cin>>qn;
for(ll i=1;i<=qn;i++){
    ll b, m, e;
    cin>>b>>m>>e;
    rotate(num+b, num+m, num+e);
}
for(ll i=0;i<n;i++){
    if(0==i) printf("%lld", num[i]);
    else printf(" %lld", num[i]);
}
puts("");

#ifdef LOCAL
fin.close();
#endif // LOCAL
}


