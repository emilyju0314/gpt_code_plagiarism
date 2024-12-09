#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

int n, q;
vector<int> c, b, x;

int F(vector<int>& a, int k) {
    if (k == 1) {
        return a[0];
    }
    
    vector<int> new_a(n);
    for (int i = 0; i < n - 1; i++) {
        new_a[i] = min(a[i], (a[i] + a[i + 1] - b[i]) / 2);
        new_a[i + 1] = max(a[i + 1], (a[i] + a[i + 1] + b[i]) / 2);
    }
    
    return F(new_a, k - 1);
}

int countGoodArrays(int k) {
    int count = 0;
    vector<int> a(n);
    
    for (int i = 0; i < 1 << n; i++) {
        bool good = true;
        for (int j = 0; j < n; j++) {
            a[j] = (i >> j) & 1 ? c[j] : 0;
            if (a[j] > c[j]) {
                good = false;
                break;
            }
        }
        
        if (good && F(a, k) >= x[k-1]) {
            count++;
        }
    }
    
    return count % MOD;
}

int main() {
    cin >> n;
    c.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    
    b.resize(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> b[i];
    }
    
    cin >> q;
    x.resize(q);
    for (int i = 0; i < q; i++) {
        cin >> x[i];
    }
    
    for (int i = 0; i < q; i++) {
        cout << countGoodArrays(i+1) << endl;
    }
    
    return 0;
}