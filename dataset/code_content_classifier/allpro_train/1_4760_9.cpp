#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <iomanip>
#include <numeric>
#include <tuple>
#include <bitset>
#include <complex>
#include <unistd.h>
#include <cassert>
#include <cctype>
#include <random>
#define _USE_MATH_DEFINES
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> plglg;
typedef tuple<int, int, int> tiii;
typedef tuple<ll, ll, ll> tlglglg;
typedef tuple<double, double, double> tddd;
typedef complex<double> xy_t;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
double pi = 3.141592653589793;
ll mod = 1000000007;
int intmax = 2147483647;
int intmin = -2147483648;
ll llmax = 9223372036854775807;
ll llmin = -9223372036854775807;
int iinf = intmax / 8;
ll inf = llmax / 8;
double eps = 1e-11;

int len;
ll p;
ll most;

ll ansdif;
ll ans;

bool b[10];
char dig[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void stbil(string s) {
    int slen = s.size();
    if (slen == len) {
        ll a = stoll(s);
        ll diff = min(abs(most - a), p - abs(most - a));
        if (diff < ansdif) {
            ans = a;
            ansdif = diff;
        } else if (diff == ansdif) {
            ans = min(ans, a);
        }
    } else {
        for (int i = 0; i < 10; i++) {
            if (!b[i]) {
                b[i] = true;
                string ss = dig[i] + s;
                stbil (ss);
                b[i] = false;
            }
        }
    }
}

int main() {
    string s;
    cin >> s;
    ll N = stoll(s);
    len = s.size();
    p = 1;
    for (int i = 0; i < len; i++) {
        p *= 10;
    }
    most = (N + p / 2) % p;
    fill(b, b + 10, false);
    ansdif = llmax;
    ans = llmax;
    stbil("");
    string ss = to_string(ans);
    int lenss = ss.size();
    for (int i = 0; i < len - lenss; i++) {
        ss = '0' + ss;
    }
    cout << ss << endl;
}

