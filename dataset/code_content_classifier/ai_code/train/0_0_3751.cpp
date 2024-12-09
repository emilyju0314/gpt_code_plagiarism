#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        long long a, b;
        cin >> a >> b;

        if (a == 0 || b == 0) {
            cout << "Second" << endl;
        } else if (a == 1) {
            cout << "First" << endl;
        } else {
            if (a > b) {
                swap(a, b);
            }
            int cnt = 0;
            while (b > 0) {
                cnt += b/a;
                b %= a; 
                swap(a, b);
            }
            if (cnt % 2 == 0) {
                cout << "Second" << endl;
            } else {
                cout << "First" << endl;
            }
        }
    }

    return 0;
}