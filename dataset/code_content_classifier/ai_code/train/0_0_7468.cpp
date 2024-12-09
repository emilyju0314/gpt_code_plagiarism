#include <iostream>
#include <string>

using namespace std;

int countOrdinary(int n) {
    string s = to_string(n);
    int numDigits = s.length();
    int numOrdinary = 0;
    for (int i = 1; i <= 9; i++) {
        int ordinaryNum = 0;
        for (int j = 0; j < numDigits; j++) {
            ordinaryNum = ordinaryNum * 10 + i;
            if (ordinaryNum <= n) {
                numOrdinary++;
            }
        }
    }
    return numOrdinary;
}

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        
        cout << countOrdinary(n) << endl;
    }
    
    return 0;
}