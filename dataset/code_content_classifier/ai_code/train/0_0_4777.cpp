#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    cin >> m;
    while (m--) {
        int k, pos;
        cin >> k >> pos;
        vector<int> sortedA = a;
        sort(sortedA.rbegin(), sortedA.rend());
        
        long long sum = 0;
        for (int i = 0; i < k; i++) {
            sum += sortedA[i];
        }
        
        cout << sum << "\n";
    }
    
    return 0;
}