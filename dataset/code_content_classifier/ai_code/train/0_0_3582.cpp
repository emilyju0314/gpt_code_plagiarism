#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    if (n % 2 == 1) {
        for (int i = 0; i < n; i++) {
            cout << i + 1 << " ";
        }
    } else {
        cout << -1;
    }
    
    return 0;
}