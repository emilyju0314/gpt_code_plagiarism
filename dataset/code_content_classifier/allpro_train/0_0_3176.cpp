#include <iostream>
#include <vector>

using namespace std;

int mod_inverse(int a, int p) {
    int res = 1;
    for (int exp = p - 2; exp; a = 1LL * a * a % p, exp >>= 1) {
        if (exp & 1) {
            res = 1LL * res * a % p;
        }
    }
    return res;
}

int main() {
    int u, v, p;
    cin >> u >> v >> p;

    int inv = mod_inverse(u, p);

    vector<int> operations;
    while (v != u) {
        if (v < u) {
            v += p;
        }
        if (1LL * (v - u) * inv % p == 1) {
            operations.push_back(1);
            v--;
        } else if (mod_inverse(u, p) != 1) {
            operations.push_back(3);
            v = 1LL * v * mod_inverse(u, p) % p;
        } else {
            operations.push_back(2);
            v--;
        }
    }

    cout << operations.size() << endl;
    for (int op : operations) {
        cout << op << " ";
    }
    cout << endl;

    return 0;
}