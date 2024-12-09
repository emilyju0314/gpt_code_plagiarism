#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> contacts(n);
    vector<string> sequences(n);

    for (int i = 0; i < n; i++) {
        cin >> contacts[i];
    }

    for (int i = 0; i < n; i++) {
        string currContact = contacts[i];
        int len = currContact.length();

        for (int j = 1; j <= len; j++) {
            string sub = currContact.substr(0, j);
            bool found = false;

            for (int k = 0; k < n; k++) {
                if (k != i && contacts[k].find(sub) != string::npos) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                sequences[i] = sub;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << sequences[i] << endl;
    }

    return 0;
}