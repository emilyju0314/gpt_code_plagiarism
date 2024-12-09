#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <ctype.h>
#include <cmath>
#include <cstdio>
#include <set>
#include <iterator>
#define pb push_back
#define lond long double
#define mp make_pair
#define all(a) a.begin(), a.end()
#define endl '\n'
typedef long long lon;
typedef unsigned long long ulon;

using namespace std;

bool camp(string a, string b){
    return a < b;
}

lon ctoi(char a){
    return a - '0';
}

vector<lon> del(lon x){
    lon square_root = sqrt(x) + 1;
    vector<lon> a;
    for (lon i = 1; i < square_root; i++) {
        if (x % i == 0 && i*i != x){
            a.pb(i);
            a.pb(x / i);
        }
        else if (x % i == 0 && i*i == x) a.pb(i);
    }
    return a;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(0); //freopen("ladder.in", "r", stdin);

    int t, n, x;
    cin >> t;
    while(t--){
        cin >> n;
        set<int> b;
        int f=0, mi=10000;
        for(int i=0;i<n;++i){cin >> x; b.emplace(x); mi=min(mi, x);}
        if(mi < 0){cout << "NO" << endl; continue;}
        while(b.size() != f && b.size() <= 300){
            f = b.size();
            for(auto p: b){
                for(auto y: b){
                    if(p==y) continue;
                    b.emplace(abs(p - y));
                }
            }
        }
        if(b.size() > 300){cout << "NO" << endl; continue;}
        cout << "YES" << endl;
        cout << b.size() << endl;
        for(auto p: b) cout << p << " ";
        cout << endl;
    }
}
