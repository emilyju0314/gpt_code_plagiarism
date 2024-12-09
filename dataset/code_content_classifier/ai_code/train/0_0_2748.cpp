#include <iostream>
using namespace std;

int main() {
    int R, G, B, N;
    cin >> R >> G >> B >> N;

    int count = 0;
    for (int r = 0; r <= N/R; r++) {
        for (int g = 0; g <= N/G; g++) {
            int remain = N - r * R - g * G;
            if (remain % B == 0 && remain >= 0) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}