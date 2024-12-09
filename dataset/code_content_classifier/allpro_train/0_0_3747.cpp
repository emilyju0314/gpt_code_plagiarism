#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        if(n == 1) {
            cout << "9" << endl;
        } else {
            cout << "9";
            for(int i = 1; i < n-1; i++) {
                cout << "0";
            }
            cout << 8 << endl;
        }
    }

    return 0;
}