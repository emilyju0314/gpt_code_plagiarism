#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isSubsequence(string s, string favorite) {
    int j = 0;
    for (int i = 0; i < favorite.size(); i++) {
        if (j < s.size() && s[j] == favorite[i]) {
            j++;
        }
    }
    return j == s.size();
}

int main() {
    int n;
    cin >> n;
    
    vector<string> strings(n);
    for (int i = 0; i < n; i++) {
        cin >> strings[i];
    }
    
    string favorite;
    cin >> favorite;
    
    int answer = 0;
    for (int i = 0; i < favorite.size(); i++) {
        bool found = false;
        for (int j = 0; j < n; j++) {
            if (isSubsequence(strings[j], favorite.substr(i))) {
                found = true;
                i = i + strings[j].size() - 1;
                answer++;
                break;
            }
        }
        if (!found) {
            cout << -1 << endl;
            return 0;
        }
    }
    
    cout << answer << endl;
    
    return 0;
}