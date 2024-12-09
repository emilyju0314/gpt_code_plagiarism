#include <iostream>
#include <vector>
#include <string>

using namespace std;

int countElements(string document, vector<string> queries) {
    int count = 0;
    for (string query : queries) {
        int pos = 0;
        bool matched = true;
        for (char c : query) {
            pos = document.find("<" + string(1, c) + ">", pos);
            if (pos == string::npos) {
                matched = false;
                break;
            }
            pos += 2 + 1; // Length of tag "<" + c + ">"
            if (pos >= document.length()) {
                matched = false;
                break;
            }
        }
        if (matched) {
            count++;
        }
    }
    return count;
}

int main() {
    string document;
    getline(cin, document);

    int m;
    cin >> m;
    cin.ignore(); // Ignore newline character

    vector<string> queries;
    for (int i = 0; i < m; i++) {
        string query;
        getline(cin, query);
        queries.push_back(query);
    }

    int numElements = countElements(document, queries);
    cout << numElements << endl;

    return 0;
}