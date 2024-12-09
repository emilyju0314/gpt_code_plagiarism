#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    string a;
    cin >> a;
    
    vector<int> factors(10, 1);
    
    for(char c : a) {
        int digit = c - '0';
        if(digit > 1) {
            if(digit == 2) factors[2] = max(factors[2], 3);
            else if(digit == 3) factors[3] = max(factors[3], 2);
            else if(digit == 4) factors[2] = max(factors[2], 2), factors[3] = max(factors[3], 2), factors[2] = max(factors[2], 2);
            else factors[digit] = max(factors[digit], digit);
        }
    }
    
    string res;
    for(int i = 9; i >= 2; i--) {
        res += string(factors[i], char(i + '0'));
    }
    
    cout << res << endl;
    
    return 0;
}