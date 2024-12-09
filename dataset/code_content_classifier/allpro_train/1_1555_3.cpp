#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <bitset>
using namespace std;

#define loop(i,a,b) for(int i=(a); i<int(b); i++)
#define rep(i,b) loop(i,0,b)
#define iter(it,c) for(auto it=(c).begin(); it!=c.end(); ++it)

typedef vector<int> vi;
typedef map<int, int> mii;

int const score[] = { 0, 0, 60, 70, 80 };
int eval(int n){
    int s = 0;
    rep(i, 5){
        s += score[n & 7];
        n >>= 3;
    }
    return s;
}

int flip(int n, int f){
    f <<= 2;
    int r = 0;
    rep(i, 5){
        int t = n >> (i * 3) & 7;
        if (t){
            int c = (f >> (i * 2) & 3) + (f >> (i * 2 + 2) & 3);
            t = ((t - 1 + c) & 3) + 1;
        }
        r |= t << (i * 3);
    }
    return r;
}

int solve(vi const& v){
    mii prev;
    prev[v[0]] = eval(v[0]);
    rep(i, 4){
        mii next;
        iter(it, prev){
            int bef = eval(it->first);
            rep(f, 1 << 8){
                int aft = flip(it->first, f);
                int suc = flip(v[i + 1], f);
                int e = it->second - bef + eval(aft) + eval(suc);
                int x = eval(aft);
                int y = eval(suc);
                if (e % 10 != 0){
                    continue;
                }
                next[suc] = max(next[suc], e);
            }
        }
        swap(prev, next);

        /*
        iter(it, prev){
            cout << bitset<15>(it->first) << " " << it->second << endl;
        }
        cout << endl;
        */
    }

    int ans = 0;
    iter(it, prev) ans = max(it->second, ans);
    return ans;
}

int main(){
    int n; cin >> n;
    while (n--){
        vi v(5);
        rep(i, 5){
            rep(j, 5){
                int t = 0; cin >> t;
                v[i] <<= 3;
                v[i] |= t;
            }
        }
        cout << solve(v) << endl;
    }
}