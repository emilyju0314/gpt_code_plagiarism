#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int median;
    if(n % 2 == 0) {
        median = m / 2;
    } else {
        median = m;
    }

    cout << 0 << " ";
    for(int i = 1; i < n - 1; i++) {
        cout << "0 ";
    }
    cout << median << endl;

    return 0;
}