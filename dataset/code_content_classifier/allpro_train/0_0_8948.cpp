#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Panel {
    int height, left, right;
};

int main() {
    int n, t;
    cin >> n >> t;

    vector<Panel> panels(n);
    for (int i = 0; i < n; i++) {
        cin >> panels[i].height >> panels[i].left >> panels[i].right;
    }

    sort(panels.begin(), panels.end(), [](const Panel& a, const Panel& b) {
        return a.height < b.height;
    });

    int max_flow = 0;
    int min_overlap = panels[0].right - panels[0].left;
    for (int i = 1; i < n; i++) {
        min_overlap = min(min_overlap, panels[i].right - panels[i].left);
        max_flow = max(max_flow, min_overlap);
    }

    cout << max_flow << endl;

    return 0;
}