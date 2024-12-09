#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    int operations = 0;
    int left = 0, right = s.size() - 1;
    
    while (left < right) {
        if (s[left] != s[right]) {
            if (s[left] == 'x') {
                left++;
                operations++;
            } else if (s[right] == 'x') {
                right--;
                operations++;
            } else {
                cout << -1 << endl;
                return 0;
            }
        } else {
            left++;
            right--;
        }
    }
    
    cout << operations << endl;
    
    return 0;
}