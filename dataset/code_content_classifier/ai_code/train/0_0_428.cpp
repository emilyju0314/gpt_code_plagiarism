#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string addBigIntegers(string num1, string num2) {
    int carry = 0;
    string result = "";
    
    int i = num1.length() - 1;
    int j = num2.length() - 1;
    
    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;
        if (i >= 0) {
            sum += num1[i] - '0';
            i--;
        }
        if (j >= 0) {
            sum += num2[j] - '0';
            j--;
        }
        
        carry = sum / 10;
        sum = sum % 10;
        
        result += to_string(sum);
    }
    
    reverse(result.begin(), result.end());
    
    return result;
}

int main() {
    string num1, num2;
    cin >> num1 >> num2;
    
    cout << addBigIntegers(num1, num2) << endl;
    
    return 0;
}