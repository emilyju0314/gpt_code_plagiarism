#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int countMatches(const vector<string>& elementStrings, const string& text) {
    int count = 0;
    string concatenatedStrings;
    // Generate all possible permutations of element strings
    do {
        concatenatedStrings.clear();
        for (const string& element : elementStrings) {
            concatenatedStrings += element;
        }
        size_t pos = 0;
        while ((pos = text.find(concatenatedStrings, pos)) != string::npos) {
            count++;
            pos++;
        }
    } while (next_permutation(elementStrings.begin(), elementStrings.end()));
    return count;
}

int main() {
    int n, m;
    while (cin >> n >> m && n != 0 && m != 0) {
        vector<string> elementStrings(n);
        for (int i = 0; i < n; i++) {
            cin >> elementStrings[i];
        }
        cin.ignore(); // Ignore newline character
        string text;
        for (int i = 0; i < m; i++) {
            string line;
            getline(cin, line);
            text += line;
        }
        
        int matches = countMatches(elementStrings, text);
        cout << matches << endl;
    }

    return 0;
}