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

        vector<int> divisors(n);
        for(int i = 0; i < n; i++) {
            cin >> divisors[i];
        }

        sort(divisors.begin(), divisors.end());

        int x = divisors[0]*divisors[n-1];
        
        bool impossible = false;
        for(int i = 0; i < n; i++) {
            if(x % divisors[i] != 0) {
                impossible = true;
                break;
            }
        }

        if(impossible) {
            cout << -1 << endl;
        } else {
            cout << x << endl;
        }
    }

    return 0;
}