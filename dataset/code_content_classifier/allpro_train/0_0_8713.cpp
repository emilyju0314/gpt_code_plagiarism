#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool isSubstring(const string &big, const string &small) {
    size_t found = big.find(small);
    if (found != string::npos) {
        return true;
    }
    return false;
}

int findMaxK(const string &newString) {
    int k = 0;
    while (true) {
        bool allSubstringsPresent = true;
        for (int i = 0; i < (1 << k); i++) {
            string binaryString;
            for (int j = 0; j < k; j++) {
                if ((i & (1 << j)) != 0) {
                    binaryString += '1';
                } else {
                    binaryString += '0';
                }
            }
            if (!isSubstring(newString, binaryString)) {
                allSubstringsPresent = false;
                break;
            }
        }
        if (!allSubstringsPresent) {
            break;
        }
        k++;
    }
    return k;
}

int main() {
    int n;
    cin >> n;

    vector<string> strings(n);
    for (int i = 0; i < n; i++) {
        cin >> strings[i];
    }

    int m;
    cin >> m;

    string newString = "";
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        newString = strings[a-1] + strings[b-1];
        strings.push_back(newString);

        int maxK = findMaxK(newString);
        cout << maxK << endl;
    }

    return 0;
}