#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<string, int> substr_counts;
    vector<string> substrings;
    
    for(int i = 0; i < n; i++) {
        string substring;
        cin >> substring;
        substr_counts[substring]++;
        substrings.push_back(substring);
    }

    string password = "";
    bool possible = true;

    for(const auto& substr_count : substr_counts) {
        if(substr_count.second % 2 != 0) {
            possible = false;
            break;
        }
        
        for(int i = 0; i < substr_count.second / 2; i++) {
            password += substr_count.first;
        }
    }

    string reversePassword = password;
    reverse(reversePassword.begin(), reversePassword.end());
    
    if(!possible) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << password + reversePassword << endl;
    }

    return 0;
}