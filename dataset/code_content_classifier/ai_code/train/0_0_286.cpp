#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    
    int operations = 0;
    
    while(a != b) {
        if(a % 2 == 0 && b % 2 == 0) {
            a /= 2;
            b /= 2;
        } else if(a % 3 == 0 && b % 3 == 0) {
            a = a * 2 / 3;
            b = b * 2 / 3;
        } else if(a % 5 == 0 && b % 5 == 0) {
            a = a * 4 / 5;
            b = b * 4 / 5;
        } else {
            cout << -1 << endl;
            return 0;
        }
        
        operations++;
    }
    
    cout << operations << endl;
    
    return 0;
}