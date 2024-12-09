#include <iostream>
using namespace std;

int countPairs(int s, int x) {
    if ((s - x) % 2 != 0 || (s < x)) {
        return 0;
    }

    int a = (s - x) / 2;
    int b = s - a;

    if ((a ^ b) == x) {
        return (a != b) ? 2 : 1;
    } else {
        return 0;
    }
}

int main() {
    int s, x;
    cin >> s >> x;

    int result = countPairs(s, x);
    cout << result << endl;

    return 0;
}