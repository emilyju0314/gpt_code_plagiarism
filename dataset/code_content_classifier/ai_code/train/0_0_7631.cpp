#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    int min_operations = 0;
    for (int i = 0; i < n; i += 2) {
        if (s[i] == s[i+1]) {
            if (s[i] == 'a') {
                s[i] = 'b';
            } else {
                s[i] = 'a';
            }
            min_operations++;
        }
    }
    
    cout << min_operations << endl;
    cout << s << endl;
    
    return 0;
}