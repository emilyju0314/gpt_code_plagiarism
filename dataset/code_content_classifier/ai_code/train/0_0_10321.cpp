#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string p(n, ' ');

        int energy = 7 * 5;

        for (int i = 0; i < n; i++) {
            string s = p;
            s[i] = 'C';
            cout << "? " << s << endl;
            cout.flush();
            int k;
            cin >> k;
            if (k == -1) {
                return 0;
            }
            energy -= 1.0 / ((i + 1) * (i + 1));

            if (energy < 0) {
                return 0;
            }

            p[i] = 'C';
        }

        for (int i = 0; i < n; i++) {
            string s = p;
            s[i] = 'H';
            cout << "? " << s << endl;
            cout.flush();
            int k;
            cin >> k;
            if (k == -1) {
                return 0;
            }
            energy -= 1.0 / ((i + 1) * (i + 1));

            if (energy < 0) {
                return 0;
            }

            if (k > 0) {
                p[i] = 'H';
            }
        }

        for (int i = 0; i < n; i++) {
            string s = p;
            s[i] = 'O';
            cout << "? " << s << endl;
            cout.flush();
            int k;
            cin >> k;
            if (k == -1) {
                return 0;
            }
            energy -= 1.0 / ((i + 1) * (i + 1));

            if (energy < 0) {
                return 0;
            }

            if (k > 0) {
                p[i] = 'O';
            }
        }

        cout << "! " << p << endl;
        cout.flush();

        int verdict;
        cin >> verdict;
        if (verdict == 0) {
            return 0;
        }
    }

    return 0;
}