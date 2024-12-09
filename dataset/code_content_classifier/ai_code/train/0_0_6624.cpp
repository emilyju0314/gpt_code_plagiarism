#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string vowels, s;
    int n, m;
    cin >> vowels >> n >> m;
    
    vector<pair<int, char>> rules[n+1];
    for(int i = 0; i < m; i++) {
        int pos1, pos2;
        char t1, t2;
        cin >> pos1 >> t1 >> pos2 >> t2;
        rules[pos1].push_back({pos2, t2});
    }
    
    cin >> s;
    
    bool found = false;
    for(int i = n-1; i >= 0; i--) {
        char current = s[i];
        for(int j = 0; j < vowels.size(); j++) {
            if(vowels[j] >= current) {
                current = vowels[j];
                s[i] = vowels[j];
                found = true;
                break;
            }
        }
        
        if(found) {
            for(int k = i+1; k < n; k++) {
                char prev = s[k-1];
                for(auto rule : rules[k]) {
                    if(prev == rule.first) {
                        s[k] = rule.second;
                        break;
                    }
                }
            }
            break;
        }
    }
    
    if(found) {
        cout << s << endl;
    } else {
        cout << "-1" << endl;
    }

    return 0;
}