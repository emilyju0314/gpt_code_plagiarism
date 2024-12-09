#include <iostream>
using namespace std;

int main() {
    int k, n, s, p;
    cin >> k >> n >> s >> p;

    int sheets_per_person = n * (k / s);
    if (k % s != 0) {
        sheets_per_person += n;
    }

    int packs_needed = sheets_per_person / p;
    if (sheets_per_person % p != 0) {
        packs_needed++;
    }

    cout << packs_needed << endl;

    return 0;
}