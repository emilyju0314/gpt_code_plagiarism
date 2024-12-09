#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int A, B, C;
        cin >> A >> B >> C;

        int ans = 0;

        for (int a = 1; a * a * a <= A * B * C; a++) {
            if ((A % a == 0) && (B % a == 0) && (C % a == 0)) {
                for (int b = a; a * b * b <= A * B * C; b++) {
                    if ((A % b == 0) && (B % b == 0) && (C % b == 0)) {
                        int c = A * B * C / (a * b);
                        if (c >= b && (A % c == 0) && (B % c == 0) && (C % c == 0)) {
                            ans += 1;
                            if (a == b && b == c) {
                                ans -= 2;
                            } else if (a == b || b == c || a == c) {
                                ans -= 1;
                            }
                        }
                    }
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}