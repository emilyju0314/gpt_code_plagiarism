#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> res(n);
    vector<int> increasing(n), decreasing(n);
    int max_increasing = -1, max_decreasing = 2e5 + 1;
    
    bool possible = true;
    for (int i = 0; i < n; i++) {
        if (a[i] > max_increasing) {
            increasing[i] = 1;
            max_increasing = a[i];
        } else if (a[i] > max_decreasing) {
            possible = false;
            break;
        } else {
            decreasing[i] = 1;
            max_decreasing = a[i];
        }
    }
    
    if (!possible) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            cout << decreasing[i] << " ";
        }
    }
    
    return 0;
}