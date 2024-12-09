#include <iostream>

using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int misha_points = max(3 * a / 10, a - a / 250 * c);
    int vasya_points = max(3 * b / 10, b - b / 250 * d);

    if (misha_points > vasya_points) {
        cout << "Misha" << endl;
    } else if (misha_points < vasya_points) {
        cout << "Vasya" << endl;
    } else {
        cout << "Tie" << endl;
    }

    return 0;
}