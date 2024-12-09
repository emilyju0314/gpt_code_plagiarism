#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    
    int mid = (n + 1) / 2;
    cout << mid << " ";
    
    for (int i = 1; i <= n; ++i) {
        if (i != mid) {
            cout << i << " ";
        }
    }
    
    cout << endl;
    
    return 0;
}