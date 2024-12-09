#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int min_lcm = INT_MAX;
    pair<int, int> indices;
    
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int lcm_val = (a[i] / gcd(a[i], a[j])) * a[j];
            if (lcm_val < min_lcm) {
                min_lcm = lcm_val;
                indices = make_pair(i+1, j+1);
            }
        }
    }
    
    cout << indices.first << " " << indices.second << endl;
    
    return 0;
} 

// This code finds the pair of indices i and j such that the value of lcm(a_i, a_j) is the minimum among all valid pairs.