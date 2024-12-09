#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    unordered_map<int, int> x_count, y_count;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x_count[x]++;
        y_count[y]++;
    }

    int max_operations = 0;

    for (auto& xc : x_count) {
        for (auto& yc : y_count) {
            int total_dots = xc.second + yc.second;
            int possible_ops = total_dots * (total_dots - 1) / 2 - xc.second * (xc.second - 1) / 2 - yc.second * (yc.second - 1) / 2;
            max_operations += possible_ops;
        }
    }

    cout << max_operations << endl;

    return 0;
}