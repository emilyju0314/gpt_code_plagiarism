#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point{
    int x, y;
};

double angle(int x, int y, int a, int b) {
    return atan2(y - b, x - a);
}

int main() {
    int n;
    cin >> n;

    int a, b, c, d;
    char c1, c2;
    cin >> a >> c >> c1 >> b >> d >> c2;

    vector<Point> stars(n);
    for(int i = 0; i < n; i++) {
        cin >> stars[i].x >> stars[i].y;
    }

    sort(stars.begin(), stars.end(), [&](Point p1, Point p2){
        return angle(p1.x, p1.y, a, b) < angle(p2.x, p2.y, a, b);
    });

    vector<int> dp(n, 1);

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(angle(stars[i].x, stars[i].y, a, b) > angle(stars[j].x, stars[j].y, a, b)) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int maxStars = *max_element(dp.begin(), dp.end());

    cout << maxStars << endl;

    return 0;
}