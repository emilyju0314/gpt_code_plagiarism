#include <iostream>
#include <vector>
#include <string>

using namespace std;

int operationsRequired(string a, string b) {
    int n = a.size();
    int flipCount = 0;
    vector<int> flipIndices;

    for (int i = n - 1; i >= 0; i--) {
        if (a[i] != b[i]) {
            flipCount++;
            if (i == 0) {
                flipIndices.push_back(i);
            } else {
                flipIndices.push_back(i - 1);
            }
        }
    }

    if (flipCount == 0) {
        return 0;
    } else if (flipCount % 2 == 0) {
        return flipCount / 2;
    } else {
        return -1;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string a, b;
        cin >> a >> b;

        int result = operationsRequired(a, b);
        cout << result << endl;
    }

    return 0;
}