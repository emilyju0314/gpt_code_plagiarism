#include <iostream>
#include <vector>
using namespace std;

int f(vector<int>& values, int l, int r) {
    int components = 0;
    bool in_range = false;
    for (int v : values) {
        if (v >= l && v <= r) {
            if (!in_range) {
                components++;
                in_range = true;
            }
        } else {
            in_range = false;
        }
    }
    return components;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> values(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }
    
    long long ans = 0;
    for (int l = 1; l <= n; l++) {
        for (int r = l; r <= n; r++) {
            ans += f(values, l, r);
        }
    }
    
    cout << ans << endl;
    
    return 0;
}