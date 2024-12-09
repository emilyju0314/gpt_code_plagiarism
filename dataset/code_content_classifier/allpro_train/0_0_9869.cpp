#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string convertToBaseM(int num, int baseM) {
    string result = "";
    
    while(num > 0) {
        int digit = num % baseM;
        result = to_string(digit) + result;
        num /= baseM;
    }
    
    return result;
}

int convertToDecimal(string num, int baseM) {
    int result = 0;
    int power = 1;
    
    for(int i = num.length() - 1; i >= 0; i--) {
        result += (num[i] - '0') * power;
        power *= baseM;
    }
    
    return result;
}

int main() {
    int A, B, C;
    
    while(cin >> A >> B >> C) {
        if(A == -1 && B == -1 && C == -1) {
            break;
        }
        
        bool valid = false;
        int minAge = INT_MAX;
        
        for(int i = 2; i <= 16; i++) {
            string A_baseM = convertToBaseM(A, i);
            string B_baseM = convertToBaseM(B, i);
            string C_baseM = convertToBaseM(C, i);
            
            if(A_baseM.length() == to_string(A).length() && B_baseM.length() == to_string(B).length()) {
                int B_decimal = convertToDecimal(B_baseM, i);
                
                if(B_decimal >= A) {
                    valid = true;
                    minAge = min(minAge, convertToDecimal(C_baseM, i));
                }
            }
        }
        
        if(valid) {
            cout << minAge << endl;
        } else {
            cout << -1 << endl;
        }
    }
    
    return 0;
}