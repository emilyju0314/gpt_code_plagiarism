#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string digits;
        cin >> digits;

        vector<char> colors(n);

        char last_color = '0';
        for (int i = 0; i < n; i++) {
            if (digits[i] >= last_color) {
                colors[i] = '1';
                last_color = digits[i];
            } else {
                colors[i] = '2';
            }
        }

        char first_color = '0';
        for (int i = 0; i < n; i++) {
            if (digits[i] < first_color) {
                cout << "-";
                break;
            }
            first_color = digits[i];
            if (i == n - 1) {
                for (int j = 0; j < n; j++) {
                    cout << colors[j];
                }
                cout << endl;
            }
        }
    }

    return 0;
}