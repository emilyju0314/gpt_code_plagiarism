#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a;

    while (a % 4 != 0) {
        a++;
    }

    cout << a << endl;

    return 0;
}