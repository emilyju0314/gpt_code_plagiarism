#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int r, b, k;
        cin >> r >> b >> k;

        // Calculate the number of painted planks in the fence
        long long totalPlanks = 0;
        long long common = r*b;

        long long commonRed = b;
        long long commonBlue = r;

        totalPlanks = common - 1 + commonBlue;

        // Check if the number of painted planks is divisible by k
        if (totalPlanks % k == 0) {
            cout << "OBEY" << endl;
        } else {
            cout << "REBEL" << endl;
        }
    }

    return 0;
}