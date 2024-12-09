#include <iostream>
using namespace std;

int main() {
    int n;
    
    while (cin >> n) {
        if (n % 2 == 0) {
            cout << n/2*3 << endl;
        } else {
            cout << n/2*3 + 1 << endl;
        }
    }
    
    return 0;
}