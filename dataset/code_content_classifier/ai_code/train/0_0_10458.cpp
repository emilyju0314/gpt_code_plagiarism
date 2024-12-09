#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    string s, t;
    cin >> s >> t;
    
    int operations = 0;
    for (int i = 0; i < N; i++) {
        if (s[i] != t[i]) {
            if (i < N - 1 && s[i] != s[i + 1] && s[i + 1] != t[i + 1]) {
                swap(s[i], s[i + 1]);
                operations++;
            } else {
                s[i] = t[i];
                operations++;
            }
        }
    }
    
    cout << operations << endl;
    
    return 0;
}