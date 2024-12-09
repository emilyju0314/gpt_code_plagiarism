#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> roads;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        roads.push_back({a, b});
    }

    string result = "";
    for (int i = 0; i < m; i++) {
        result += (i % 2 == 0) ? "i" : "o";
    }

    cout << result << endl;

    return 0;
}