#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Rect {
    int x1, y1, x2, y2;
};

bool overlap(const Rect& r1, const Rect& r2) {
    return (r1.x1 < r2.x2 && r1.x2 > r2.x1 && r1.y1 < r2.y2 && r1.y2 > r2.y1);
}

int main() {
    int N;
    cin >> N;

    vector<Rect> rects(N);
    vector<int> count(N, 0);

    for (int i = 0; i < N; i++) {
        cin >> rects[i].x1 >> rects[i].y1 >> rects[i].x2 >> rects[i].y2;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j && overlap(rects[i], rects[j])) {
                count[i]++;
            }
        }
    }

    int maxOverlaps = *max_element(count.begin(), count.end());

    cout << maxOverlaps << endl;

    return 0;
}