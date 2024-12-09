#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Segment {
    int left, right;
};

bool compare(Segment a, Segment b) {
    return a.left < b.left;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        vector<Segment> segments(n);
        vector<int> points;
        for (int i = 0; i < n; i++) {
            cin >> segments[i].left >> segments[i].right;
            points.push_back(segments[i].left);
            points.push_back(segments[i].right);
        }

        sort(points.begin(), points.end());

        int max_union = 0;
        for (int i = 0; i < points.size(); i++) {
            for (int j = 0; j < points.size(); j++) {
                if (i != j) {
                    int count = 0;
                    for (int k = 0; k < n; k++) {
                        if ((segments[k].left <= points[i] && points[i] <= segments[k].right) || 
                            (segments[k].left <= points[j] && points[j] <= segments[k].right)) {
                            count++;
                        }
                    }
                    max_union = max(max_union, count);
                }
            }
        }

        cout << max_union << endl;
    }

    return 0;
}