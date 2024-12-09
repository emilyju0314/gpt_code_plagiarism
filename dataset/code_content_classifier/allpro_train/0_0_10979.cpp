#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    string A;
    cin >> A;

    set<string> uniqueStrings;

    // Case 1: Reversing the whole string
    string reversedA = A;
    reverse(reversedA.begin(), reversedA.end());
    uniqueStrings.insert(reversedA);

    // Case 2: Reversing a substring
    for (int i = 0; i < A.size(); i++) {
        for (int j = i; j < A.size(); j++) {
            string temp = A;
            reverse(temp.begin() + i, temp.begin() + j + 1);
            uniqueStrings.insert(temp);
        }
    }

    cout << uniqueStrings.size() << endl;

    return 0;
}