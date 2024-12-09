#include <iostream>
#include <string>

using namespace std;

string addLeadingZeros(string num, int len) {
    while(num.length() < len) {
        num = "0" + num;
    }
    return num;
}

string findNumberB(string a, string s) {
    int len = max(a.length(), s.length());
    a = addLeadingZeros(a, len);
    s = addLeadingZeros(s, len);
    
    string b = "";
    int carry = 0;
    
    for(int i = len-1; i >= 0; i--) {
        int sum = (s[i] - '0') - carry - (a[i] - '0');
        if(sum < 0) {
            sum += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        b = to_string(sum) + b;
    }
    
    if(carry == 1) {
        return "-1";
    } else {
        return b;
    }
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        string a, s;
        cin >> a >> s;
        
        string b = findNumberB(a, s);
        
        cout << b << endl;
    }
    
    return 0;
}