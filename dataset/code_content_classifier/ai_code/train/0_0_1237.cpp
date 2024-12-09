#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> l(m);
    for (int i = 0; i < m; i++) {
        cin >> l[i];
    }
    
    int sum = 0;
    for (int i = 0; i < m; i++) {
        sum += l[i];
    }
    
    if (sum > n) {
        cout << -1 << endl;
    } else {
        int start = 1;
        for (int i = 0; i < m; i++) {
            int p = min(start, n - l[i] + 1);
            cout << p << " ";
            start = p + l[i];
        }
        cout << endl;
    }
    
    return 0;
}