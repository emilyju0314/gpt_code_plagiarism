#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Segment {
    int left, right, index;
};

bool compareSegments(const Segment& s1, const Segment& s2) {
    return s1.left < s2.left;
}

int main() {
    int n;
    cin >> n;

    vector<Segment> segments(n);
    for (int i = 0; i < n; i++) {
        cin >> segments[i].left >> segments[i].right;
        segments[i].index = i;
    }

    sort(segments.begin(), segments.end(), compareSegments);

    vector<int> ans(n, 0);

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (i != j && segments[j].left <= segments[i].right && segments[j].right >= segments[i].right) {
                count++;
            }
        }
        ans[segments[i].index] = count;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}