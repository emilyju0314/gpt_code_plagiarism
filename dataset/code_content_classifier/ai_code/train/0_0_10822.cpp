#include <iostream>
#include <string>

using namespace std;

bool isEqual(string A, string B, int start) {
    for (int i = 0; i < B.length(); i++) {
        if (A[start + i] != B[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    string A, B, C;
    getline(cin, A);
    getline(cin, B);
    getline(cin, C);

    string newString = "";
    bool replaced = false;

    int i = 0;
    while (i < A.length()) {
        bool found = isEqual(A, B, i);

        if (found && !replaced) {
            newString += C;
            i += B.length();
            replaced = true;
        } else {
            newString += A[i];
            i++;
        }
    }

    cout << newString << endl;

    return 0;
}