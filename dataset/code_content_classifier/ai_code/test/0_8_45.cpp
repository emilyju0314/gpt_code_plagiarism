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
        int consecutiveDays = 0;
        bool died = false;
        
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                if (i > 0 && a[i - 1] == 1) {
                    height += 5;
                } else {
                    height++;
                }
                consecutiveDays = 0;
            } else {
                consecutiveDays++;
                if (consecutiveDays >= 2) {
                    died = true;
                    break;
                }
            }
        }
        
        if (died) {
            cout << "-1" << endl;
        } else {
            cout << height << endl;
        }
    }
    
    return 0;
}