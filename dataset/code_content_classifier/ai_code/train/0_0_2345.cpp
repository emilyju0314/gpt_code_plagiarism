#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Robot {
    int position;
    int radius;
    int IQ;
};

int main() {
    int N, K;
    cin >> N >> K;

    vector<Robot> robots(N);
    for (int i = 0; i < N; i++) {
        cin >> robots[i].position >> robots[i].radius >> robots[i].IQ;
    }

    int pairs = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            int distance = abs(robots[i].position - robots[j].position);
            int IQ_diff = abs(robots[i].IQ - robots[j].IQ);
            if (distance <= robots[i].radius && IQ_diff <= K) {
                pairs++;
            }
        }
    }

    cout << pairs << endl;

    return 0;
}