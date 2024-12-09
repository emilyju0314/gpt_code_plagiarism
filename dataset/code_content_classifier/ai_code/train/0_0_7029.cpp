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
        vector<int> b(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        
        bool sorted = true;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) {
                sorted = false;
                break;
            }
        }
        
        if (sorted) {
            cout << "Yes" << endl;
        } else {
            bool canSort = false;
            for (int i = 0; i < n - 1; i++) {
                if (b[i] != b[i + 1]) {
                    canSort = true;
                    break;
                }
            }
            
            if (canSort) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}