#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

vector<int> parent;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) parent[y] = x;
}

int main() {
    int n, m;
    cin >> n >> m;

    parent.resize(n+1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    int cnt_love = 0, cnt_hate = 0;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (c == 1) {
            unite(a, b);
            cnt_love++;
        } else {
            cnt_hate++;
        }
    }

    int components = 0;
    for (int i = 1; i <= n; i++) {
        if (parent[i] == i) components++;
    }

    if (cnt_love + cnt_hate == n*(n-1)/2) {
        cout << 0 << endl;
    } else if (cnt_love == 0) {
        cout << (n * (n-1) % MOD * (n-2) % MOD) % MOD << endl;
    } else {
        cout << (1LL << components-1) - components << endl;
    }

    return 0;
}