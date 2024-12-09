#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct Segment {
    int left, right;
};

bool compareSegments(const Segment& s1, const Segment& s2) {
    return s1.left < s2.left;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<Segment> segments(n);
    for(int i = 0; i < n; i++) {
        cin >> segments[i].left >> segments[i].right;
    }

    sort(segments.begin(), segments.end(), compareSegments);

    vector<int> points(2*n);
    for(int i = 0; i < n; i++) {
        points[2*i] = segments[i].left;
        points[2*i+1] = segments[i].right;
    }

    sort(points.begin(), points.end());

    set<int> currentSegments;
    vector<Segment> result;

    for(int i = 0; i < 2*n; i++) {
        if(i % 2 == 0) { // left endpoint
            currentSegments.insert(i/2);
        } else { // right endpoint
            currentSegments.erase(i/2);
        }

        if(currentSegments.size() >= k) {
            result.push_back({points[i], points[i+1]});
        }
    }

    cout << result.size() << endl;
    for(auto segment : result) {
        cout << segment.left << " " << segment.right << endl;
    }

    return 0;
}