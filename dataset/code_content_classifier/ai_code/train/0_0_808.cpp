#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> b(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> b[i][j];
        }
    }

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        int val = b[i][0];
        for(int j = 1; j < n; j++) {
            val &= b[i][j];
        }
        a[i] = val;
    }

    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    
    return 0;
}