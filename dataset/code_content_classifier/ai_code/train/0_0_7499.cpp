#include <iostream>
#include <string>

using namespace std;

string addDigits(string num) {
    string result = "";
    for (int i = 0; i < num.size(); i++) {
        result += num[i];
        if (i != num.size() - 1) {
            result += "+";
        }
    }
    return result;
}

int main() {
    int N;
    cin >> N;
    
    string A0;
    cin >> A0;
    
    // Ensure the final result is less than 10
    while (A0.size() > 1) {
        cout << addDigits(A0) << endl;
        
        int sum = 0;
        for (int i = 0; i < A0.size(); i++) {
            sum += A0[i] - '0';
        }
        
        A0 = to_string(sum);
    }
    
    cout << addDigits(A0) << endl; // Output the final single digit number
    
    return 0;
}