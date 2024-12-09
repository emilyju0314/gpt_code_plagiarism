#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int count = 0;
    for (int i = 0; i < s.length()-1; i++) {
        if (s[i] != s[i+1]) {
            count++;
        }
    }
    
    if (s[0] != s[s.length()-1]) {
        if (s[0] == 'A' && s[s.length()-1] == 'B') {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}