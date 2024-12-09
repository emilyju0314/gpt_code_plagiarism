#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    // Check if a has duplicates
    for(int i = 1; i < n; i++) {
        if(a[i] == a[i-1]) {
            cout << -1 << endl;
            return 0;
        }
    }

    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        b[i] = a[(i + 1) % n];
    }

    for(int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << endl;

    return 0;
}