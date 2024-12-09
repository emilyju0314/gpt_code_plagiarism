#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Segment {
    int left;
    int right;
    int index;
};

bool compareSegments(const Segment &s1, const Segment &s2) {
    return s1.left < s2.left;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<Segment> segments(n);
    for (int i = 0; i < n; i++) {
        cin >> segments[i].left >> segments[i].right;
        segments[i].index = i + 1;
    }

    sort(segments.begin(), segments.end(), compareSegments);

    vector<int> badPoints(201, 0);
    for (int i = 0; i < n; i++) {
        for (int j = segments[i].left; j <= segments[i].right; j++) {
            badPoints[j]++;
        }
    }

    vector<int> removedSegments;
    for (int i = 0; i < n; i++) {
        bool remove = false;
        for (int j = segments[i].left; j <= segments[i].right; j++) {
            if (badPoints[j] > k) {
                remove = true;
                break;
            }
        }
        if (remove) {
            badPoints[segments[i].right + 1] = 0;
            removedSegments.push_back(segments[i].index);
        }
    }

    cout << removedSegments.size() << endl;
    for (int i = 0; i < removedSegments.size(); i++) {
        cout << removedSegments[i] << " ";
    }

    return 0;
}