#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        cout << arr[x-1] << endl;
    }
    
    for (int i = 1; i <= n; i++) {
        bool found = false;
        for (int j = 0; j < m; j++) {
            if (i == x[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            cout << i << endl;
        }
    }
    
    return 0;
}