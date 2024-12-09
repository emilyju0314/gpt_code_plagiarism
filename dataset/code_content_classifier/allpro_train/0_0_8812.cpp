#include <iostream>

using namespace std;

int main() {
    long long X, Y;
    cin >> X >> Y;

    int maxLength = 1;
    long long currentNum = X;

    while (currentNum * 2 <= Y) {
        currentNum *= 2;
        maxLength++;
    }

    cout << maxLength << endl;

    return 0;
}