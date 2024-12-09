#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    long long maxBeauty;
    int leftMost;
    int rightMost;
};

void buildSegmentTree(vector<Node> &segmentTree, vector<int> &a, vector<int> &b, int node, int start, int end) {
    if (start == end) {
        segmentTree[node] = {a[start], start, end};
    } else {
        int mid = (start + end) / 2;
        buildSegmentTree(segmentTree, a, b, 2 * node + 1, start, mid);
        buildSegmentTree(segmentTree, a, b, 2 * node + 2, mid + 1, end);
        
        segmentTree[node] = {max(segmentTree[2 * node + 1].maxBeauty, segmentTree[2 * node + 2].maxBeauty), start, end};
    }
}

void updateSegmentTree(vector<Node> &segmentTree, int node, int idx, int newVal, int newB) {
    if (segmentTree[node].leftMost == idx && segmentTree[node].rightMost == idx) {
        segmentTree[node].maxBeauty = newVal;
    } else {
        int mid = (segmentTree[node].leftMost + segmentTree[node].rightMost) / 2;
        
        if (idx <= mid) {
            updateSegmentTree(segmentTree, 2 * node + 1, idx, newVal, newB);
        } else {
            updateSegmentTree(segmentTree, 2 * node + 2, idx, newVal, newB);
        }
        
        segmentTree[node].maxBeauty = max(segmentTree[2 * node + 1].maxBeauty, segmentTree[2 * node + 2].maxBeauty);
    }
}

long long querySegmentTree(vector<Node> &segmentTree, int node, int start, int end) {
    if (segmentTree[node].leftMost >= start && segmentTree[node].rightMost <= end) {
        return segmentTree[node].maxBeauty;
    }

    if (segmentTree[node].rightMost < start || segmentTree[node].leftMost > end) {
        return LLONG_MIN;
    }

    return max(querySegmentTree(segmentTree, 2 * node + 1, start, end), querySegmentTree(segmentTree, 2 * node + 2, start, end));
}

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> a(2 * N), b(2 * N);
    for (int i = 0; i < 2 * N; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < 2 * N; i++) {
        cin >> b[i];
    }

    vector<Node> segmentTree(4 * N);

    buildSegmentTree(segmentTree, a, b, 0, 0, 2 * N - 1);

    for (int q = 0; q < Q; q++) {
        int p, x, y;
        cin >> p >> x >> y;
        p--;

        updateSegmentTree(segmentTree, 0, p, x, y);

        cout << querySegmentTree(segmentTree, 0, 0, 2 * N - 1) << "\n";
    }

    return 0;
}