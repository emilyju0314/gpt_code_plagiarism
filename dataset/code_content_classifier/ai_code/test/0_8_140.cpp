#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        int count = 0;
        for (int j = 1; j*j <= n; j++) {
            for (int k = 1; k*k <= n; k++) {
                if (j*j <= n && k*k <= n) {
                    count++;
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}