#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> p(n);
        for(int i = 0; i < n; i++) {
            cin >> p[i];
        }

        vector<int> a(n);
        for(int i = n - 1; i >= 0; i--) {
            if(p[i] == 1) {
                a[i] = 1;
                continue;
            }
            a[i] = -p[i];
            for(int j = i + 1; j < n; j++) {
                if(p[j] > p[j-1] && a[j] == a[j-1]) {
                    a[j] = -a[j];
                }
            }
        }

        bool valid = true;
        for(int i = 1; i < n; i++) {
            if(p[i] < p[i-1] || a[i] <= a[i-1]) {
                valid = false;
                break;
            }
        }

        if(!valid) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for(int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}