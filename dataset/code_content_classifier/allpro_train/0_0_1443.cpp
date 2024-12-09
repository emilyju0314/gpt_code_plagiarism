#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if(n == 1) {
        cout << "0" << endl;
    } else {
        int cost = (n - 1) / 2;
        cout << cost << endl;
    }

    return 0;
}