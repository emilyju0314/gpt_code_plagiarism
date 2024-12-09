#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int t1, t2;
    cin >> t1 >> t2;

    int cinema_x, cinema_y;
    int house_x, house_y;
    int shop_x, shop_y;
    cin >> cinema_x >> cinema_y;
    cin >> house_x >> house_y;
    cin >> shop_x >> shop_y;

    double min_distance = abs(cinema_x - house_x) + abs(cinema_y - house_y);

    double max_distance = 0.0;

    // Calculate the maximum distance that Alan and Bob can cover together
    if (t1 > t2) {
        swap(t1, t2);
    }

    if (t1 * 2 >= min_distance) {
        max_distance = min_distance / 2.0;
    } else {
        max_distance = max(t1 + t2 + sqrt(pow(cinema_x - shop_x, 2) + pow(cinema_y - shop_y, 2)),
                           sqrt(pow(cinema_x - house_x, 2) + pow(cinema_y - house_y, 2)));
    }

    cout << fixed << max_distance << endl;

    return 0;
}