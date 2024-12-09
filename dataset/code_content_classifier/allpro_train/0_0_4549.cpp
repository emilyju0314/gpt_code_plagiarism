#include <iostream>
#include <bitset>
#include <map>

using namespace std;

int main() {
    int q;
    cin >> q;

    multiset<int> A;
    A.insert(0);

    for (int i = 0; i < q; ++i) {
        char op;
        int x;
        cin >> op >> x;

        if (op == '+') {
            A.insert(x);
        } else if (op == '-') {
            A.erase(A.find(x));
        } else {
            int max_xor = 0;
            for (int y : A) {
                max_xor = max(max_xor, x ^ y);
            }
            cout << max_xor << endl;
        }
    }

    return 0;
}