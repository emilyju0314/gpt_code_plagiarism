#include <iostream>
#include <string>

using namespace std;

bool isValidEmail(const string& email) {
    if (email.empty()) return false;
    
    size_t pos = email.find('@');
    if (pos == string::npos || pos == 0 || pos == email.length() - 1) return false;
    
    string A = email.substr(0, pos);
    string B = email.substr(pos + 1);
    
    for (char c : A) {
        if (c < 'a' || c > 'z') return false;
    }
    
    for (char c : B) {
        if (c < 'a' || c > 'z') return false;
    }
    
    return true;
}

int main() {
    string addresses;
    cin >> addresses;
    
    string result;
    bool valid = false;
    
    for (int i = 0; i < addresses.length(); i++) {
        string temp = addresses;
        temp.insert(i, ",");
        
        size_t pos = 0;
        while (pos < temp.length()) {
            pos = temp.find(',', pos);
            string email = temp.substr(pos == 0 ? pos : pos - 1, temp.find(',', pos + 1) - pos);
            if (isValidEmail(email)) {
                if (!valid) {
                    result = email;
                    valid = true;
                } else {
                    result += "," + email;
                }
                pos += email.length();
            } else {
                break;
            }
        }
        
        if (valid) break;
    }
    
    if (!valid) {
        cout << "No solution" << endl;
    } else {
        cout << result << endl;
    }
    
    return 0;
}