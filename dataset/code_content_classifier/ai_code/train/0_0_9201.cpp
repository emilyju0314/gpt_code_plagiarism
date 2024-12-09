#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    
    string s;
    cin >> s;
    
    vector<char> unique_chars;
    for (char c : s) {
        if (find(unique_chars.begin(), unique_chars.end(), c) == unique_chars.end()) {
            unique_chars.push_back(c);
        }
    }
    
    sort(unique_chars.begin(), unique_chars.end());
    
    map<char, int> char_count;
    for (char c : s) {
        char_count[c]++;
    }
    
    int count_obtainable = 0;
    vector<char> obtainable_chars;
    
    for (char c : unique_chars) {
        int m = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == c) {
                m++;
            }
        }
        
        if ((long long)a * (m + 1) <= 1LL * b * char_count[c]) {
            count_obtainable++;
            obtainable_chars.push_back(c);
        }
    }
    
    cout << count_obtainable << endl;
    for (char c : obtainable_chars) {
        cout << c << " ";
    }
    
    return 0;
}