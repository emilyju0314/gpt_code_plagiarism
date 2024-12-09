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

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        cout << sum / m << " ";
        sum %= m;
    }
    
    return 0;
}