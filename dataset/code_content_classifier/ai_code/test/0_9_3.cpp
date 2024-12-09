#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int count_possible_integers(string s) {
    int count = 0;
    
    // Handling case when s is 0, as it will always be divisible by 25
    if (s == "0") {
        return 1;
    }
    
    // Handling case when s contains X
    if (s.find("X") != string::npos) {
        char X_digit;
        for (char c : s) {
            if (c == 'X') {
                X_digit = c;
                break;
            }
        }
        
        for (int i = 0; i <= 9; i++) {
            string temp_s = s;
            replace(temp_s.begin(), temp_s.end(), X_digit, '0' + i);
            count += count_possible_integers(temp_s);
        }
    } 
    // Handling case when s contains _ but not X
    else if (s.find("_") != string::npos) {
        for (int i = 0; i <= 9; i++) {
            string temp_s = s;
            replace(temp_s.begin(), temp_s.end(), '_', '0' + i);
            if (temp_s[0] != '0' && stoi(temp_s) % 25 == 0) {
                count++;
            }
        }
    }
    // Handling case when s does not contain any _ or X
    else {
        if (s[0] != '0' && stoi(s) % 25 == 0) {
            count = 1;
        }
    }
    
    return count;
}

int main() {
    string s;
    cin >> s;
    
    int result = count_possible_integers(s);
    cout << result << endl;
    
    return 0;
}