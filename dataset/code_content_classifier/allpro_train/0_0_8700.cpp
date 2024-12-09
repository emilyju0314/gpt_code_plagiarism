#include <iostream>
using namespace std;

int main() {
    int a, b, c, l;
    cin >> a >> b >> c >> l;

    long long count = 0;

    for (int i = 0; i <= l; i++) {
        for (int j = 0; j <= l; j++) {
            for (int k = 0; k <= l; k++) {
                if (i + j + k <= l) {
                    long long sides[3] = {a + i, b + j, c + k};
                    if (sides[0] < sides[1] + sides[2] && sides[1] < sides[0] + sides[2] && sides[2] < sides[0] + sides[1]) {
                        count++;
                    }
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}