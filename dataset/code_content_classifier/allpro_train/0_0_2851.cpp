#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, H, W;
    cin >> N >> H >> W;

    vector<int> inner(N/2, 0);
    vector<int> outer(N/2, 0);

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (i % 2 == 0) {
            outer[i/2] = x;
        } else {
            inner[i/2] = x;
        }
    }

    int total_open_area = 0;
    for (int i = 0; i < N/2; i++) {
        total_open_area += (W - inner[i] - outer[i]) * H;
    }

    cout << total_open_area << endl;

    return 0;
}