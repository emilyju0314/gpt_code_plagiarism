#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> house(n);
    for(int i = 0; i < n; i++) {
        cin >> house[i];
    }

    int seconds = 0;
    int direction = 1; // 1 for right, -1 for left
    int height = n - 1, width = 0;

    while(height > 0) {
        if(width < 0 || width >= m) {
            cout << "Never" << endl;
            return 0;
        }

        if(house[height][width] == '.') {
            seconds++;
            height--;
        } else if(house[height][width] == '+') {
            seconds += 2;
            house[height][width] = '.';
            direction *= -1;
        } else {
            seconds++;
            direction *= -1;
        }

        width += direction;
    }

    cout << seconds << endl;

    return 0;
}