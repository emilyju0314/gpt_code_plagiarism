#include <iostream>
using namespace std;

int main() {
    int q;
    cin >> q;

    for(int i = 0; i < q; i++) {
        int l, r, d;
        cin >> l >> r >> d;

        if(d < l) {
            cout << d << endl;
        } else {
            int x = (r/d + 1) * d;
            cout << x << endl;
        }
    }

    return 0;
}