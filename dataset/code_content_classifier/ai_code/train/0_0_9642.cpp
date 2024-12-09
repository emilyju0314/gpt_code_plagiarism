#include <iostream>
using namespace std;

int findMaxK(int n) {
    int k = 0;
    while ((n & (n - k)) != 0) {
        k |= (k + 1);
    }
    return k;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int result = findMaxK(n);
        cout << result << endl;
    }

    return 0;
}