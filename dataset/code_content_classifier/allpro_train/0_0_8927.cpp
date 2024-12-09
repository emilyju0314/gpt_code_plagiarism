#include <iostream>

using namespace std;

int main() {
    int q;
    cin >> q;

    for(int i = 0; i < q; i++) {
        int b, w;
        cin >> b >> w;

        // Check for impossible cases
        if (b > w*3 + 1 || w > b*3 + 1) {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;

        if (b >= w) {
            for (int j = 0; j < w; j++) {
                cout << "2 " << j*2+2 << endl;
            }

            for (int j = 0; j < w; j++) {
                if (b > 0) {
                    cout << "1 " << j*2+2 << endl;
                    b--;
                }
            }

            // in case b is still greater than w
            if (b > 0) {
                cout << "1 2" << endl;
                b--;
            }
        } else {
            for (int j = 0; j < b; j++) {
                cout << "2 " << j*2+2 << endl;
            }

            for (int j = 0; j < b; j++) {
                if (w > 0) {
                    cout << "3 " << j*2+2 << endl;
                    w--;
                }
            }

            // in case w is still greater than b
            if (w > 0) {
                cout << "3 2" << endl;
                w--;
            }
        }
    }

    return 0;
}