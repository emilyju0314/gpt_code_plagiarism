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
        vector<int> a(n);

        for(int i = 0; i < n; i++) {
            cin >> p[i];
        }

        bool possible = true;

        for(int i = 0; i < n; i++) {
            if(p[i] != i+1) {
                a[i] = (i+1);
            } else {
                a[i] = -(i+1);
            }
        }

        for(int i = 1; i < n; i++) {
            if(abs(a[i]) < abs(a[i-1])) {
                possible = false;
                break;
            }
        }

        if(possible) {
            cout << "YES\n";
            for(int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << "\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}