#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long emptyCells = (3LL * n * n) % 1000003;
    cout << emptyCells << endl;

    return 0;
}