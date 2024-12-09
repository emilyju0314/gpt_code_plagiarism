#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

using State = string::const_iterator;

int digit(State &s){
    int ret = *s - '0';
    s++;
    return ret;
}

int term(State &s){
    int ans = digit(s);
    while(true){
        if(*s == '*'){
            s++;
            ans *= digit(s);
        }else break;
    }
    return ans;
}

int expr(State &s){
    int ans = term(s);
    while(true){
        if(*s == '+'){
            s++;
            ans += term(s);
        }else break;
    }
    return ans;
}

int expr2(State &s){
    int ans = digit(s);
    while(true){
        if(*s == '+'){
            s++;
            ans += digit(s);
        }else if(*s == '*'){
            s++;
            ans *= digit(s);
        } else break;
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    int x = 0;
    cin >> x;
    State p = s.begin();
    int a = expr(p);
    p = s.begin();
    int b = expr2(p);
    string ans = "IMLU";
    cout << ans[(a==x)+(b==x)*2] << "\n";
    return 0;
}
