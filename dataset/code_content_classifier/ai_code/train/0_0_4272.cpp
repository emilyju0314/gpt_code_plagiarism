#include <iostream>
#include <string>

using namespace std;

bool is_divisor(string s1, string s2) {
    if(s2.length() % s1.length() != 0) return false;
    string repeated = "";
    int count = s2.length() / s1.length();
    for(int i = 0; i < count; i++) {
        repeated += s1;
    }
    return repeated == s2;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    
    int count = 0;
    int maxLength = min(s1.length(), s2.length());
    
    for(int i = 1; i <= maxLength; i++) {
        if(s1.length() % i == 0 && s2.length() % i == 0) {
            if(is_divisor(s1.substr(0, i), s1) && is_divisor(s1.substr(0, i), s2)) {
                count++;
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}