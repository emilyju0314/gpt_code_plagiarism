#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long d = 0;
        for(int i = 1; i < n; i++) {
            if(a[i] % a[0] != 0) {
                d = a[0];
                break;
            }
        }

        if(d == 0) {
            cout << 0 << endl;
        } else {
            cout << d << endl;
        }
    }

    return 0;
}