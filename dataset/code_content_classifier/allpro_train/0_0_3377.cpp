#include <iostream>
#include <string>
using namespace std;

string remainderOfBigIntegers(string A, int B) {
    int remainder = 0;
    for(int i = 0; i < A.length(); i++) {
        remainder = (remainder * 10 + (A[i] - '0')) % B;
    }
    return to_string(remainder);
}

int main() {
    string A;
    int B;
    cin >> A >> B;
    
    cout << remainderOfBigIntegers(A, B) << endl;
    
    return 0;
}