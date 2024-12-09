#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    int a;
    int colors[9] = {0};

    for (int i = 0; i < N; i++) {
        cin >> a;
        if (a < 400) {
            colors[0]++;
        } else if (a < 800) {
            colors[1]++;
        } else if (a < 1200) {
            colors[2]++;
        } else if (a < 1600) {
            colors[3]++;
        } else if (a < 2000) {
            colors[4]++;
        } else if (a < 2400) {
            colors[5]++;
        } else if (a < 2800) {
            colors[6]++;
        } else if (a < 3200) {
            colors[7]++;
        } else {
            colors[8]++;
        }
    }

    int min_colors = 0;
    int max_colors = 0;
    for (int i = 0; i < 8; i++) {
        if (colors[i] > 0) {
            min_colors++;
            max_colors++;
        }
    }

    if (colors[8] > 0) {
        min_colors = max(min_colors, 1);
        max_colors += colors[8];
    }

    cout << min_colors << " " << max_colors << endl;

    return 0;
}