#include <iostream>
#include <vector>

using namespace std;

int main() {
    int p;
    cin >> p;

    vector<int> a(p);
    for (int i = 0; i < p; i++) {
        cin >> a[i];
    }

    vector<int> b(p, 0);

    for (int i = 0; i < p; i++) {
        int val = a[i];
        for (int j = 0; j < p; j++) {
            b[i] = (b[i] + val * (i == 0 ? 1 : j) % p) % p;
            val = (val * (p - i) % p);
        }
    }

    for (int i = 0; i < p; i++) {
        cout << b[i] << " ";
    }
    cout << endl;

    return 0;
}