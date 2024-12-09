#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // Check if it is possible to split the sequence
        int prev = a[0];
        bool possible = false;
        for(int i = 1; i < n; i++) {
            if(a[i] < prev) {
                possible = true;
                break;
            } 
            prev = a[i];
        }

        if(possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}