#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> substrings;
    set<char> uniqueChars;

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            cout << "? " << i << " " << j << endl;
            string response;
            cin >> response;

            for (char c : response) {
                uniqueChars.insert(c);
            }
        }
    }

    string possibleString;
    for (char c : uniqueChars) {
        possibleString += c;
    }

    sort(possibleString.begin(), possibleString.end());

    cout << "! " << possibleString << endl;
    
    return 0;
}