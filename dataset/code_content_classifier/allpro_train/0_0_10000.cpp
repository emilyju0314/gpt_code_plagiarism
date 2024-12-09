#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct RestPoint {
    int x;
    int b;
};

bool cmp(RestPoint a, RestPoint b) {
    return a.x < b.x;
}

int main() {
    int n, l;
    cin >> n >> l;

    vector<RestPoint> restPoints(n);
    for(int i = 0; i < n; i++) {
        cin >> restPoints[i].x >> restPoints[i].b;
    }

    sort(restPoints.begin(), restPoints.end(), cmp);

    vector<double> dp(n);
    vector<int> parent(n);

    dp[0] = 0;
    parent[0] = 0;

    for(int i = 1; i < n; i++) {
        double minFrustration = 1e9;
        int bestParentIndex = -1;
        for(int j = 0; j < i; j++) {
            double frustration = dp[j] + sqrt((double)(restPoints[i].x - restPoints[j].x) - l) / restPoints[i].b;
            if(frustration < minFrustration) {
                minFrustration = frustration;
                bestParentIndex = j;
            }
        }
        dp[i] = minFrustration;
        parent[i] = bestParentIndex;
    }

    vector<int> path;
    int index = n - 1;
    while(index != parent[index]) {
        path.push_back(index + 1);
        index = parent[index];
    }
    path.push_back(1);

    reverse(path.begin(), path.end());

    for(int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }

    cout << endl;

    return 0;
}