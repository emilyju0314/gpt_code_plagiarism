#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int a, b, n;
        cin >> a >> b >> n;

        int operations = 0;
        
        while (max(a, b) <= n) {
            if (a < b) {
                a += b;
            } else {
                b += a;
            }
            
            operations++;
        }

        cout << operations << endl;
    }

    return 0;
}