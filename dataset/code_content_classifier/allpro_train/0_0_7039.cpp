#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    if (n == 0) {
        cout << "0 0 0" << endl;
    } else if (n == 1) {
        cout << "0 0 1" << endl;
    } else {
        cout << "0 1 " << n-1 << endl;
    }

    return 0;
}