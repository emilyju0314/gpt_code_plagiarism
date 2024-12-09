#include <iostream>

using namespace std;

int main() {
    int n, m, s;
    long long t;
    cin >> n >> m >> s >> t;

    if (s <= m) {
        for (long long i = t; i > 0; i--) {
            s++;
            if (s > n) {
                s = 1;
            }
        }
    } else {
        for (long long i = t; i > 0; i--) {
            s--;
            if (s < 1) {
                s = n;
            }
        }
    }

    cout << s << endl;

    return 0;
}