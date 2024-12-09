#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> roads;

    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        roads.push_back({a, b});
    }

    cout << "1" << endl;
    cout << roads[0].first << " " << roads[0].second << " 1 " << n << endl;

    return 0;
}