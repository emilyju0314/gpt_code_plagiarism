#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        if(n < 4) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for(int i = 2; i <= n; i += 2) {
                cout << i << " ";
            }
            for(int i = 1; i < n; i += 2) {
                cout << i << " ";
            }
            cout << endl;
        }
    }

    return 0;
}