#include <iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<cmath>
#include<map>

using namespace std;
#define ll long long
const long double pi = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679;
struct node {
private:
    ll ans = 0;
    node *left = nullptr;
    node *right = nullptr;
public:
    void update(ll l, ll r, ll idx, ll x) {
        if (r - l == 1) {
            ans = max(ans, x);
            return;
        }
        ll m = (l + r) / 2;
        ll L = 0, R = 0;
        if (idx < m) {
           if (left == nullptr)
               left = new node;
           left->update(l, m, idx, x);
           L = left->ans;
        } else {
            if (right == nullptr)
                right = new node;
            right->update(m, r, idx, x);
            R = right->ans;
        }
        if (left != nullptr)
            L = left->ans;
        if (right != nullptr)
            R = right->ans;
        ans = max(L, R);
    }
    ll get(ll l, ll r, ll ql, ll qr) {
        if (ql <= l && r <= qr) {
            return ans;
        }
        if (ql >= r || l >= qr)
            return 0;
        ll m = (l + r) / 2;
        ll ret = 0;
        if (!(ql >= m || l >= qr)) {
            if (left != nullptr)
                ret = max(ret, left->get(l, m, ql, qr));
        }
        if (!(ql >= r || m >= qr)) {
            if (right != nullptr)
                ret = max(ret, right->get(m, r, ql, qr));
        }
        return ret;
    }
};
struct pie {
    ll r, h;
};
long double volume(pie a) {
    return (pi * a.r * a.r) * a.h;
}
ll not_pi_volume(pie a) {
    return (a.r * a.r) * a.h;
}
int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<ll> arr(n);
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        cout << 3 * n << "\n";
        for (int i = 0; i < n; i += 2) {
            cout << "2 " << i + 1 << " " << i + 2 << "\n";
            cout << "2 " << i + 1 << " " << i + 2 << "\n";
            cout << "1 " << i + 1 << " " << i + 2 << "\n";
            cout << "2 " << i + 1 << " " << i + 2 << "\n";
            cout << "2 " << i + 1 << " " << i + 2 << "\n";
            cout << "1 " << i + 1 << " " << i + 2 << "\n";
        }
    }
}
