#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<pair<int, int>> operations;
    int swaps = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (isPrime(j - i + 1) && a[i] > a[j]) {
                swap(a[i], a[j]);
                swaps++;
                operations.push_back({i+1, j+1});
            }
        }
    }
    
    cout << swaps << endl;
    for (auto op : operations) {
        cout << op.first << " " << op.second << endl;
    }
    
    return 0;
}