#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        int x = 0, y = 0;
        for (int i = 0; i < n; ++i) {
            x += a[i] * i;
            y += b[i] * i;
        }

        cout << "The bi-valuation is " << (x == y ? "correct" : "incorrect") << "." << endl;
    }
    return 0;
}
