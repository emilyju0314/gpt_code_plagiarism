#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

int d, n;
vector<string> passwords;
unordered_set<string> visited;
vector<int> ans;

bool check_all_passwords() {
    for (string password : passwords) {
        if (visited.find(password) == visited.end()) {
            return false;
        }
    }
    return true;
}

void dfs(string current_sequence) {
    if (check_all_passwords()) {
        cout << current_sequence.size() << endl;
        for (char c : current_sequence) {
            if (c == ' ') {
                cout << "R ";
            } else {
                cout << c << " ";
            }
        }
        exit(0);
    }
    
    for (int i = 0; i < d; i++) {
        string next_sequence = current_sequence;
        bool reset = false;
        for (string password : passwords) {
            if (password[i] == '1') {
                next_sequence += to_string(i) + " ";
                if (!reset) {
                    next_sequence += "R ";
                    reset = true;
                }
            }
        }
        if (visited.find(next_sequence) == visited.end()) {
            visited.insert(next_sequence);
            dfs(next_sequence);
        }
    }
}

int main() {
    cin >> d >> n;
    
    for (int i = 0; i < n; i++) {
        string password;
        cin >> password;
        passwords.push_back(password);
    }
    
    dfs("");
    
    return 0;
}