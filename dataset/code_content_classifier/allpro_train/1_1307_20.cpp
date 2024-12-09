#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b) do { cout << "["; for (int count = (a);count < (b);++count) cout << ary[count] << ((b)-1 == count ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

template<typename T1,typename T2>ostream& operator<<(ostream& os,const pair<T1,T2>& a) {os << "(" << a.first << ", " << a.second << ")";return os;}

const char newl = '\n';

int main() {
    int a[4];
    for (int i = 0;i < 4;++i) cin >> a[i];
    int sum = 0,ans = 100000;
    for (int i = 0;i < 4;++i) sum += a[i];
    for (int i = 0;i < 4;++i) for (int j = i+1;j < 4;++j) ans = min(ans,abs(sum-(a[i]+a[j])*2));
    cout << ans << endl;
}
