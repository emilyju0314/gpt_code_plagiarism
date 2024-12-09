#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    if(n == 0) {
        cout << 1 << endl;
    } else {
        int lastDigit = n % 4;
        if(lastDigit == 0) {
            cout << 6 << endl;
        } else {
            int result = 1;
            for(int i = 0; i < lastDigit; i++) {
                result = (result * 8) % 10;
            }
            cout << result << endl;
        }
    }
    
    return 0;
}