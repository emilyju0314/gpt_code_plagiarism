#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isEmpty(string s) {
    while (true) {
        int i = 0;
        while (i < s.length() - 1) {
            if (s[i] == s[i + 1]) {
                if (s[i] == 'z') {
                    s.erase(i, 2);
                } else {
                    char c = s[i] + 1;
                    s.replace(i, 2, 1, c);
                }
                break;
            }
            i++;
        }
        if (i == s.length() - 1) {
            break;
        }
    }
    if (s.empty()) {
        return true;
    }
    return false;
}

int main() {
    string s;
    cin >> s;
    
    int Q;
    cin >> Q;
    
    vector<pair<int, int>> queries(Q);
    for (int i = 0; i < Q; i++) {
        cin >> queries[i].first >> queries[i].second;
    }
    
    for (pair<int, int> query : queries) {
        string sub = s.substr(query.first - 1, query.second - query.first + 1);
        if (isEmpty(sub)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}