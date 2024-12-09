#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    int insertions = 0;
    for (int i = 0; i < s.length(); i++) {
        int j = i;
        while (j < s.length() && s[j] == s[i]) {
            j++;
        }
        if ((j - i) % 2 == 0) {
            insertions += 1;
        }
        i = j - 1; // Move i to the end of the current maximal sequence
    }
    
    cout << insertions << endl;
    
    return 0;
}