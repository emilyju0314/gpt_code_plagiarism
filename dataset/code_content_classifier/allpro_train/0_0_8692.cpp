#include <iostream>
#include <string>

using namespace std;

int main() {
    int k, x, n, m;
    cin >> k >> x >> n >> m;
    
    // Check if it's possible to achieve x occurrences of substring "AC" with given constraints
    if (x > n || x > m) {
        cout << "Happy new year!" << endl;
        return 0;
    }
    
    string s1, s2;
    
    // Determine the strings so that sk has exactly x occurrences of substring "AC"
    if (k % 2 == 0) {
        s1 = string(n, 'A');
        s2 = string(m, 'C');
    } else {
        s1 = string(n, 'C');
        s2 = string(m, 'A');
    }
    
    cout << s1 << endl;
    cout << s2 << endl;
    
    return 0;
}