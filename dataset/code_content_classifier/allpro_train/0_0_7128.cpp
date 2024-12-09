#include <iostream>

using namespace std;

int main() {
    int n, m, s;
    cin >> n >> m >> s;

    int count = 0;
    for (int a = 0; a <= n; ++a) {
        for (int b = 0; b <= m; ++b) {
            for (int c = 0; c <= n; ++c) {
                for (int d = 0; d <= m; ++d) {
                    for (int x0 = 1; x0 <= n; ++x0) {
                        for (int y0 = 1; y0 <= m; ++y0) {
                            if ((2*a + 1)*(2*b + 1) + (2*c + 1)*(2*d + 1) - 1 == s) {
                                count++;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}