#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, x;
        cin >> n >> x;
        
        int floor = 1 + (n - 1) / x;
        cout << floor << endl;
    }

    return 0;
}