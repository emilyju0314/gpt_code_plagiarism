#include <iostream>

using namespace std;

int main() {
    long long n, sx, sy, dx, dy, t;
    cin >> n >> sx >> sy >> dx >> dy >> t;

    // Calculate the total number of steps the bear will take
    long long total_steps = min(t, min(sx - 1, n - sx) / abs(dx) + min(t, min(sy - 1, n - sy) / abs(dy));

    // Calculate the final position of the bear
    long long final_x = (sx + total_steps*dx + n - 1) % n + 1;
    long long final_y = (sy + total_steps*dy + n - 1) % n + 1;

    cout << final_x << " " << final_y << endl;

    return 0;
}