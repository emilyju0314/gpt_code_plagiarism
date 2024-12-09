#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    unordered_set<int> ancientNumbers;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        ancientNumbers.insert(c);
    }

    bool canUnderstand = true;
    for (int ancient : ancientNumbers) {
        if (k % ancient == 0) {
            canUnderstand = false;
            break;
        }
    }

    if (canUnderstand) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}