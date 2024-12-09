#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    string T;
    cin >> T;

    unordered_set<string> S;
    string currentString;
    for (char c : T) {
        currentString += c;
        S.insert(currentString);
    }

    cout << S.size() << endl;

    return 0;
}