#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
    int n, sum = 0;
    cin >> n;
    vector<int> a(n + 2);
    a.at(0) = 0;
    a.at(n + 1) = 0;
    rep(i, n) cin >> a.at(i + 1);
    rep(i, n + 1) sum += abs(a.at(i + 1) - a.at(i));
    rep(i, n) cout << sum - abs(a.at(i + 1) - a.at(i)) - abs(a.at(i + 2) - a.at(i + 1)) + abs(a.at(i + 2) - a.at(i)) << endl;
}