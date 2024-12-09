#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    long long total = 0;
    int prev = a[0];
    for (int i = 1; i < n; i++) {
        int diff = a[i] - prev;
        if (diff < 0) {
            diff += m;
        }
        total += diff;
        prev = a[i];
    }
    
    cout << total << endl;
    
    return 0;
}