#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        char c;
        cin >> n >> c;

        string s;
        cin >> s;

        vector<int> operations;
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == c) {
                count++;
            }
        }

        if (count == 0) {
            cout << "1\n";
            for (int i = 2; i <= n; i++) {
                if (n % i == 0) {
                    cout << i << endl;
                    break;
                }
            }
        } else {
            cout << n - count << endl;
            for (int i = 1; i < n; ++i) {
                if (s[i] != c) {
                    cout << i << " ";
                }
            }
            cout << "\n";
        }
    }

    return 0;
}