#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    int originalN = N;
    int reverseN = 0;
    
    while(N > 0) {
        int digit = N % 10;
        reverseN = reverseN * 10 + digit;
        N = N / 10;
    }
    
    if(originalN == reverseN) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}