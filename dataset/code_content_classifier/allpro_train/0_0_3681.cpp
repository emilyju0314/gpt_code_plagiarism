#include <iostream>
#include <string>

using namespace std;

int main() {
    string word;
    cin >> word;

    string target = "CODEFORCES";
    int n = word.size();

    bool found = false;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            string sub = word.substr(0, i) + word.substr(j + 1);
            if (sub == target) {
                found = true;
                break;
            }
        }
        if (found) break;
    }

    if (found) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}