#include <iostream>
#include <string>
using namespace std;

int minDeletedCharacters(string s, string t) {
    int i = 0, j = 0;
    int deleted = 0;
    
    while (i < s.size() && j < t.size()) {
        if (s[i] == t[j]) {
            i++;
            j++;
        } else if (s[i] == '.') {
            i++;
        } else {
            i++;
            deleted++;
        }
    }
    
    if (j < t.size()) {
        deleted += t.size() - j;
    }
    
    return deleted;
}

int main() {
    string s, t;
    cin >> s >> t;

    int result = minDeletedCharacters(s, t);
    cout << result << endl;

    return 0;
}