#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<int> keys(n);
        for (int i = 0; i < n; i++) {
            cin >> keys[i];
        }
        string stations;
        cin >> stations;

        string decrypted = "";
        for (char c : stations) {
            int index = islower(c) ? c - 'a' : c - 'A' + 26;
            for (int key : keys) {
                index = (index - key + 52) % 52;
            }
            decrypted += (index < 26) ? 'a' + index : 'A' + index - 26;
        }

        cout << decrypted << endl;
    }

    return 0;
}