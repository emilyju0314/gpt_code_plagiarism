#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const long long mod = 1e9 + 7;

vector<long long> F(vector<long long>& a) {
    int n = a.size();
    if (n == 1) {
        return a;
    }
    vector<long long> odd, even;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            even.push_back(a[i]);
        } else {
            odd.push_back(a[i]);
        }
    }
    vector<long long> f_odd = F(odd);
    vector<long long> f_even = F(even);
    
    vector<long long> result;
    for (int i = 0; i < f_odd.size(); i++) {
        result.push_back(f_odd[i]);
    }
    for (int i = 0; i < f_even.size(); i++) {
        result.push_back(f_even[i]);
    }
    
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    
    vector<long long> b = F(a);
    
    for (int i = 0; i < m; i++) {
        int l, r, u, v;
        cin >> l >> r >> u >> v;
        
        long long sum = 0;
        for (int j = l-1; j < r; j++) {
            if (b[j] >= u && b[j] <= v) {
                sum += b[j];
            }
        }
        
        cout << sum % mod << endl;
    }
    
    return 0;
}