#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    vector<int> freq(26, 0);
    for(char c : s) {
        freq[c-'a']++;
    }
    
    sort(freq.begin(), freq.end(), greater<int>());
    
    string t = "";
    for(int i = 0; i < 26; i++) {
        t += string(freq[i], 'a' + i);
    }
    
    cout << t << endl;
    
    return 0;
}