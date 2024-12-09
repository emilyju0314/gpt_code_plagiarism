#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int total_cost = 0;
    for (int i = 0; i < n; i++) {
        int length, width, height;
        cin >> length >> width >> height;

        int perimeter = 2 * (length + width);
        total_cost += perimeter * height;
    }

    int m;
    cin >> m;

    int min_cost = INT_MAX;
    for (int i = 0; i < m; i++) {
        int roll_length, roll_width, price;
        cin >> roll_length >> roll_width >> price;

        int rolls_needed = total_cost / roll_width;
        if (total_cost % roll_width != 0) {
            rolls_needed++;
        }

        min_cost = min(min_cost, rolls_needed * price);
    }

    cout << min_cost << endl;

    return 0;
}