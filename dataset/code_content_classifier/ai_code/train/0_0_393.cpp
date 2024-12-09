#include <iostream>

using namespace std;

int main() {
    int s, v1, v2, t1, t2;
    cin >> s >> v1 >> v2 >> t1 >> t2;

    int time_first = s * v1 + 2 * t1;
    int time_second = s * v2 + 2 * t2;

    if (time_first < time_second) {
        cout << "First" << endl;
    } else if (time_first > time_second) {
        cout << "Second" << endl;
    } else {
        cout << "Friendship" << endl;
    }

    return 0;
}