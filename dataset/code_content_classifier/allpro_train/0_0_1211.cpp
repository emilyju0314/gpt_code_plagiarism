#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string A, B;
    cin >> A >> B;

    bool found = false;
    for (int i = 0; i <= A.length() - B.length(); i++) {
        bool match = true;
        for (int j = 0; j < B.length(); j++) {
            if (B[j] != '_' && A[i+j] != B[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}