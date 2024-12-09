#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;

        if(n == 1) {
            if(k == 1) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else if(m < n*(n-1)/2) {
            if(k > 2) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
            }
        } else {
            if(k > 3) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
            }
        }
    }

    return 0;
}