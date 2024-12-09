#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

void solve(string s){
    int id = 0, nxt = 1;
    int zen = 0, aku = 0;
    for (auto &&i : s) (i == 'o' ? zen : aku)++;
    if(zen < aku){
        puts("-1");
        return;
    }else if(zen == aku){
        for (int i = 0; i < s.size(); i += 2) {
            if(s[i]^s[i+1]^'o'^'x') {
                puts("-1");
                return;
            }
        }
        cout << s.size()/2-1 << "\n";
        for (int i = 0; i+2 < s.size(); i += 2) {
            printf("split %d %d\n", i, 1);
        }
        return;
    }
    vector<tuple<int, int, int>> ans;
    while(s.size() > 2){
        if(all_of(s.begin(),s.end(), [&](char c){ return c == 'o'; })){
            ans.emplace_back(0, id, 0);
            s = s.substr(1, s.size());
            id = nxt++;
            id = nxt++;
            continue;
        }
        if(!(s[0]^s[1]^'o'^'x')){
            ans.emplace_back(0, id, 1);
            s = s.substr(2, s.size());
            id = nxt++;
            id = nxt++;
            continue;
        }
        if(!(s.back()^s.end()[-2]^'o'^'x')){
            ans.emplace_back(0, id, s.size()-3);
            s = s.substr(0, s.size()-2);
            id = nxt++;
            nxt++;
            continue;
        }
        if(s.front() == 'o'){
            ans.emplace_back(0, id, 0);
            ans.emplace_back(1, nxt+1, nxt);
            id = nxt+2;
            nxt = nxt+3;
            s = s.substr(1, s.size())+'o';
        }else if(s.back() == 'o') {
            ans.emplace_back(0, id, s.size()-2);
            ans.emplace_back(1, nxt+1, nxt);
            s = 'o'+s.substr(0, s.size()-1);
            id = nxt+2;
            nxt = nxt+3;
        }else {
            int cur = 0, cnt = 0;
            for (int i = 0; i < s.size(); ++i) {
                cnt += (s[i] == 'o' ? 1 : -1);
                if(cnt == 1) {
                    cur = i;
                    break;
                }
            }
            ans.emplace_back(0, id, cur);
            ans.emplace_back(1, nxt+1, nxt);
            rotate(s.begin(), s.end()-cur, s.end());
            id = nxt+2;
            nxt = nxt+3;
        }
    }
    cout << ans.size() << "\n";
    for (auto &&j : ans) {
        int a, b, c; tie(a, b, c) = j;
        if(a == 0) printf("split %d %d\n", b, c);
        else printf("join %d %d\n", b, c);
    }
}

int main() {
    int q;
    cin >> q;
    while(q--){
        string s;
        cin >> s;
        solve(s);
    }
    return 0;
}
