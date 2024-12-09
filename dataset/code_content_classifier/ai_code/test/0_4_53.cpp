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

        int count = 0;
        vector<int> operations;

        for (int i = 1; i <= n; i++) {
            bool allEqual = true;
            for (int j = i-1; j < n; j += i) {
                if (s[j] != c) {
                    allEqual = false;
                    break;
                }
            }

            if (!allEqual) {
                count++;
                operations.push_back(i);
            }
        }

        cout << count << endl;
        for (int i = 0; i < operations.size(); i++) {
            cout << operations[i] << " ";
        }
        cout << endl;
    }

    return 0;
}