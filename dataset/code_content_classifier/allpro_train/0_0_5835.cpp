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

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }

    for (int q = 0; q < m; q++) {
        int p, v;
        cin >> p >> v;
        
        sum -= a[p-1];
        a[p-1] = v;
        sum += a[p-1];

        cout << sum << endl;
    }
    
    return 0;
}