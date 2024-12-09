#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<string> pin_codes(n);
        map<string, int> freq;

        for (int j = 0; j < n; j++) {
            cin >> pin_codes[j];
            freq[pin_codes[j]]++;
        }

        int changes = 0;

        for (int j = 0; j < n; j++) {
            if (freq[pin_codes[j]] > 1) {
                changes++;
                for (char& c : pin_codes[j]) {
                    if (freq[pin_codes[j]] > 1 && c != '9') {
                        c = '9';
                        freq[pin_codes[j]]--;
                    }
                }
                freq[pin_codes[j]]++;
            }
        }

        cout << changes << endl;

        for (int j = 0; j < n; j++) {
            cout << pin_codes[j] << endl;
        }
    }

    return 0;
}