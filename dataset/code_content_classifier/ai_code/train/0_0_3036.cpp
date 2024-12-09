#include <iostream>
using namespace std;

int countDigits(int n) {
    int count = 0;
    while (n > 0) {
        count++;
        n /= 10;
    }
    return count;
}

int main() {
    int h, m, k;
    cin >> h >> m >> k;

    int h1, m1, h2, m2;
    cin >> h1 >> m1 >> h2 >> m2;

    int count = 0;

    for (int i = h1; i <= h2; i++) {
        for (int j = (i == h1 ? m1 : 0); j < (i == h2 ? m2 : m); j++) {
            int prevTime = i * m + j;
            int nextTime = (i * m + j + 1) % (h * m);
            
            int prevDigits = countDigits(prevTime);
            int nextDigits = countDigits(nextTime);

            int changedDigits = 0;
            int prev = prevTime, next = nextTime;
            while (prev > 0 || next > 0) {
                if (prev % 10 != next % 10) {
                    changedDigits++;
                }
                prev /= 10;
                next /= 10;
            }

            if (changedDigits >= k) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}