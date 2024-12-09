#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int totalHours = 0;
    int remainingCandles = a;

    while(remainingCandles > 0) {
        totalHours += remainingCandles;
        int newCandles = remainingCandles / b;
        remainingCandles = remainingCandles % b + newCandles;
        if (remainingCandles < b) {
            totalHours += remainingCandles;
            break;
        }
    }

    cout << totalHours << endl;

    return 0;
}