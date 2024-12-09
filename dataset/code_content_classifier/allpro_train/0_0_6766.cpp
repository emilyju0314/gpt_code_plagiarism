#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        vector<int> toBeRemoved;
        int r = 0;

        for (int i = 0; i < s.length(); i++) {
            if (i < s.length() - 2 && s.substr(i, 3) == "one") {
                r++;
                toBeRemoved.push_back(i+2);
            } else if (i < s.length() - 2 && s.substr(i, 3) == "two") {
                r++;
                toBeRemoved.push_back(i+2);
            }
        }

        cout << r << endl;
        for (int i = 0; i < r; i++) {
            cout << toBeRemoved[i] + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}