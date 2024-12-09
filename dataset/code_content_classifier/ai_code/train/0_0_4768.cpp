#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Check if all elements are already zero
    bool all_zero = true;
    for(int i = 0; i < n; i++) {
        if(a[i] == 1) {
            all_zero = false;
            break;
        }
    }
    
    if(all_zero) {
        cout << "YES" << endl;
        cout << "0" << endl;
    } else {
        vector<vector<int>> operations;
        
        int m = 0;
        for(int i = 0; i < n-2; i++) {
            if(a[i] == 1) {
                m++;
                a[i] ^= 1; a[i+1] ^= 1; a[i+2] ^= 1;
                operations.push_back({i+1, i+2, i+3});
            }
        }
        
        // Check if all elements have been turned to zero
        bool all_zero_now = true;
        for(int i = 0; i < n; i++) {
            if(a[i] == 1) {
                all_zero_now = false;
                break;
            }
        }
        
        if(all_zero_now) {
            cout << "YES" << endl;
            cout << m << endl;
            for(auto op : operations) {
                for(int val : op) {
                    cout << val << " ";
                }
                cout << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}