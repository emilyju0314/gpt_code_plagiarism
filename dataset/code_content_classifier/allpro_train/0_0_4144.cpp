#include <iostream>
#include <vector>

using namespace std;

struct LineSegment {
    int px, py, qx, qy;
};

bool isSegmentValid(const LineSegment& newSegment, const vector<LineSegment>& segments) {
    for (const LineSegment& segment : segments) {
        if (newSegment.px == segment.px && newSegment.qx == segment.qx && ((segment.py <= newSegment.py && newSegment.py <= segment.qy) || (segment.py <= newSegment.qy && newSegment.qy <= segment.qy))) {
            return false;
        }
        if (newSegment.py == segment.py && newSegment.qy == segment.qy && ((segment.px <= newSegment.px && newSegment.px <= segment.qx) || (segment.px <= newSegment.qx && newSegment.qx <= segment.qx))) {
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    cin >> N;

    vector<LineSegment> segments;
    for (int i = 0; i < N; i++) {
        LineSegment newSegment;
        cin >> newSegment.px >> newSegment.py >> newSegment.qx >> newSegment.qy;

        if (isSegmentValid(newSegment, segments)) {
            cout << "1" << endl;
            segments.push_back(newSegment);
        } else {
            cout << "0" << endl;
        }
    }

    return 0;
}