#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int prev = 0, count = 0, stones = 0;
    while (stones <= n) {
        stones += prev;
        prev++;
        count++;
    }

    cout << count - 1 << endl;

    return 0;
}