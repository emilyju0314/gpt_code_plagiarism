#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    pair<int, int> points[n+1];
    for(int i = 0; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = make_pair(x, y);
    }

    int count = 0;
    for(int i = 1; i < n; i++) {
        if((points[i].first > points[i-1].first && points[i+1].second < points[i].second) ||
           (points[i].first < points[i-1].first && points[i+1].second > points[i].second)) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}