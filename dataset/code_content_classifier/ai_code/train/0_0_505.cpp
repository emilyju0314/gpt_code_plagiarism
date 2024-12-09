#include <iostream>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    if (d == 1) {
        cout << n*(n-1)/2 << endl;
    } else {
        cout << n*d - (d*(d+1))/2 << endl;
    }

    return 0;
}