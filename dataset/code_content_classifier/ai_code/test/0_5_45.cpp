Here is the code to solve this problem:

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        int height = 1;
        int consecutive_days_without_water = 0;
        
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                if (i > 0 && a[i - 1] == 1) {
                    height += 5;
                } else {
                    height += 1;
                }
                consecutive_days_without_water = 0;
            } else {
                consecutive_days_without_water++;
                if (consecutive_days_without_water == 2) {
                    cout << -1 << endl;
                    break;
                }
            }
        }
        
        if (consecutive_days_without_water < 2) {
            cout << height << endl;
        }
    }
    
    return 0;
} 

You can copy and paste this code into your C++ compiler to run it and test it with the provided input example.