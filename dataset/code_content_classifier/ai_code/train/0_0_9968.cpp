#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> b(n), g(n);
    
    if (k < n || k == 1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        
        for (int i = 0; i < n; i++) {
            b[i] = i % k + 1;
            g[i] = (i + 1) % k + 1;
            
            cout << b[i] << " " << g[i] << endl;
        }
    }

    return 0;
}