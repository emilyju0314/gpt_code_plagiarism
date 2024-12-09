#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    if (k > (n-1)/2) {
        cout << "No";
    } else {
        cout << "Yes" << endl;
        cout << k + 1 << endl;
        cout << 1 << " ";
        for (int i = 2; i <= n && k > 0; ++i) {
            if (i != k + 1) {
                cout << i << " ";
                k--;
            }
        }
    }

    return 0;
}