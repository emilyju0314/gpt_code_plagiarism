#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a, b, c, n;
    cin >> a >> b >> c >> n;

    vector<vector<int>> points(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> points[i][j];
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if ((a * points[i][0] + b * points[i][1] + c * points[i][2] + 4) > 0){
            count++;
        }
    }

    cout << count << endl;

    return 0;
}