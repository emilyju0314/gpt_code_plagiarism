#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

unordered_set<string> equivalentPasswords;

void dfs(vector<string>& passwords, int index) {
    equivalentPasswords.insert(passwords[index]);
    
    for (int i = 0; i < passwords.size(); i++) {
        if (index != i && passwords[index].find_first_of(passwords[i]) != string::npos && equivalentPasswords.find(passwords[i]) == equivalentPasswords.end()) {
            dfs(passwords, i);
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<string> passwords(n);
    for (int i = 0; i < n; i++) {
        cin >> passwords[i];
    }
    
    for (int i = 0; i < n; i++) {
        if (equivalentPasswords.find(passwords[i]) == equivalentPasswords.end()) {
            dfs(passwords, i);
        }
    }
    
    cout << equivalentPasswords.size() << endl;
    
    return 0;
}