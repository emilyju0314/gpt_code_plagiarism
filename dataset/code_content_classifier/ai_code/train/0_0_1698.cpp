#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    if(n <= 2) {
        cout << "0" << endl;
    } else if (n % 2 == 0) {
        cout << "2" << endl;
    } else {
        cout << "4" << endl;
    }

    return 0;
}