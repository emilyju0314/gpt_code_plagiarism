#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> points(N);
    for(int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = make_pair(x, y);
    }

    long long min_area = LLONG_MAX;
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            int xmin = min(points[i].first, points[j].first);
            int xmax = max(points[i].first, points[j].first);
            int ymin = min(points[i].second, points[j].second);
            int ymax = max(points[i].second, points[j].second);
            
            int count = 0;
            for(int k = 0; k < N; k++) {
                if(points[k].first >= xmin && points[k].first <= xmax && points[k].second >= ymin && points[k].second <= ymax) {
                    count++;
                }
            }
            
            if(count >= K) {
                long long area = (long long)(xmax - xmin) * (long long)(ymax - ymin);
                min_area = min(min_area, area);
            }
        }
    }

    cout << min_area << endl;

    return 0;
}