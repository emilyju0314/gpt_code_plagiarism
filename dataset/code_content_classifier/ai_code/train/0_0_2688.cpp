#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int min_neg_idx = -1;
    int max_val_idx = 0;
    
    for (int i = 0; i < n; i++) {
        if (a[i] < 0 && (min_neg_idx == -1 || a[i] > a[min_neg_idx])) {
            min_neg_idx = i;
        }
        if (a[i] > a[max_val_idx]) {
            max_val_idx = i;
        }
    }
    
    cout << "1 " << max_val_idx + 1 << " " << min_neg_idx + 1 << endl;
    
    for (int i = 0; i < n; i++) {
        if (i != max_val_idx && i != min_neg_idx) {
            cout << "1 " << min_neg_idx + 1 << " " << i + 1 << endl;
        }
    }
    
    return 0;
}