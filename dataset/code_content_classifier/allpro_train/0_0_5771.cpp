#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int x;
        cin >> x;

        if(x == 0) {
            cout << "1 1" << endl;
        } else {
            int n = sqrt(x) + 1;
            int m = (n + 1) / 2;
            cout << n << " " << m << endl;
        }
    }

    return 0;
}