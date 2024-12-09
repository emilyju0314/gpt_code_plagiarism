#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        long long s, n, k;
        cin >> s >> n >> k;

        long long total_pens = s / n;
        long long remaining_animals = s % n;

        if (total_pens >= k || (remaining_animals + total_pens) >= k) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}