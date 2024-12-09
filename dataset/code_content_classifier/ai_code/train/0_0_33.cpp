#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<int, int> x_count, y_count;
    unordered_map<string, int> point_count;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        
        x_count[x]++;
        y_count[y]++;
        point_count[to_string(x) + "," + to_string(y)]++;
    }

    int count = 0;
    for (auto it = point_count.begin(); it != point_count.end(); it++) {
        int x, y;
        x = stoi(it->first.substr(0, it->first.find(",")));
        y = stoi(it->first.substr(it->first.find(",") + 1));

        count += ((x_count[x] - 1) * (y_count[y] - 1) * it->second);
    }

    cout << count << endl;

    return 0;
}