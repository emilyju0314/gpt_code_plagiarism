#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if(n < 4 || (n % 7 == 2) || (n % 7 == 4)) {
        cout << -1 << endl;
    } else {
        cout << "4";
        for(int i = 1; i <= n/7; i++) {
            cout << "7";
        }
        cout << endl;
    }

    return 0;
}