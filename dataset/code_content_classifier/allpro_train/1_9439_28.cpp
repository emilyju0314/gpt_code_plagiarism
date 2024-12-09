#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <deque>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>
#include <iterator>
#include <bitset>
#include <numeric>
#include <list>
#include <iomanip>
#include <cassert>
#include <array>
#include <tuple>
#include <initializer_list>
#include <unordered_set>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <deque>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>
#include <iterator>
#include <bitset>
#include <numeric>
#include <list>
#include <iomanip>
#include <cassert>
#include <array>
#include <tuple>
#include <initializer_list>
#include <unordered_set>
#include <unordered_map>
#include <forward_list>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)

using hash_t = unsigned long long;

struct rolloing_hash {
    int n, b;
    vector<hash_t> pow, hash;
    
    rolloing_hash() {}
    
    rolloing_hash(const string &s, hash_t b_ = 10007) {
        set(s, b_);
    }
    
    void set(const string &s, hash_t b_ = 10007) {
        n = s.size();
        b = b_;
        calc_pow();
        calc_hash(s.c_str());
    }

    void calc_pow() {
        pow.resize(n + 1); pow[0] = 1;
        for (int i = 0; i < n; i++) {
            pow[i + 1] = pow[i] * b;
        }
    }
    
    void calc_hash(const char *s) {
        hash.resize(n + 1);
        hash[0] = 0;
        for (int i = 0; i < n; i++) {
            hash[i + 1] = s[i] + hash[i] * b;
        }
    }
    
    hash_t get(int i) const {
        return hash[i]; 
    }
    
    hash_t get(int i, int j) const {
        return get(j) - get(i) * pow[j - i];
    }
};

using RH = rolloing_hash;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int a = n % 2 == 0 ? 2 : 1;
    int b = n % 2 == 0 ? n / 2 - 1 : n / 2;
    int c = b + a;
    int d = n - a;
    RH rh(s);
    int ans = n;
    while (a < b) {
        hash_t A = rh.get(0, a);
        if (rh.get(b, c) == A && rh.get(d, n) == A && rh.get(a, b) == rh.get(c, d)) {
            ans = min(ans, b);
        }
        a += 2;
        b -= 1;
        c += 1;
        d -= 2;
    }
    if (ans != n) {
        cout << "Love " << s.substr(0, ans) << '!';
    } else {
        cout << "mitomerarenaiWA";
    }
    cout << '\n';
}