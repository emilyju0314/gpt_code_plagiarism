#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    
    int n = s.size(), m = t.size();
    string s_repeat = "";
    for (int i = 0; i < 100; i++) {
        s_repeat += s;
    }
    
    int i = 0, j = 0, count = 0;
    while (i < s_repeat.size() && j < m) {
        if (s_repeat[i] == t[j]) {
            j++;
            count++;
        }
        i++;
    }
    
    if (count == m) {
        cout << i - m + 1 << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}