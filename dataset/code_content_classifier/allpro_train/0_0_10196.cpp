#include <iostream>
using namespace std;

int main() {
    string S;
    cin >> S;

    int max_consecutive_rainy_days = 0;
    int consecutive_rainy_days = 0;

    for (int i = 0; i < 3; i++) {
        if (S[i] == 'R') {
            consecutive_rainy_days++;
            max_consecutive_rainy_days = max(max_consecutive_rainy_days, consecutive_rainy_days);
        } else {
            consecutive_rainy_days = 0;
        }
    }

    cout << max_consecutive_rainy_days << endl;

    return 0;
}