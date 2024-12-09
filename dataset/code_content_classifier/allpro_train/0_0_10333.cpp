#include <iostream>
#include <string>

using namespace std;

int main() {
    string a, s;
    cin >> a >> s;
    
    for (int i = 0; i < s.length(); i++) {
        char max_digit = s[i];
        for (int j = 0; j < a.length(); j++) {
            if (a[j] < max_digit) {
                a[j] = max_digit;
                break;
            }
        }
    }
    
    cout << a << endl;
    
    return 0;
}