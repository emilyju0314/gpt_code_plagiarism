#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool matchesPattern(string pattern, string filename) {
    if (pattern.size() != filename.size()) {
        return false;
    }
    
    for (int i = 0; i < pattern.size(); i++) {
        if (pattern[i] != '?' && pattern[i] != filename[i]) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<string> filenames(n);
    for (int i = 0; i < n; i++) {
        cin >> filenames[i];
    }
    
    vector<int> deleteIndices(m);
    for (int i = 0; i < m; i++) {
        cin >> deleteIndices[i];
        deleteIndices[i]--;
    }
    
    string pattern = filenames[deleteIndices[0]];
    
    for (int i = 1; i < m; i++) {
        string cur = filenames[deleteIndices[i]];
        for (int j = 0; j < pattern.size(); j++) {
            if (pattern[j] != cur[j]) {
                pattern[j] = '?';
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (find(deleteIndices.begin(), deleteIndices.end(), i) == deleteIndices.end()) {
            if (matchesPattern(pattern, filenames[i])) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    
    cout << "Yes" << endl;
    cout << pattern << endl;
    
    return 0;
}