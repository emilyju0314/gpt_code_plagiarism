#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> edges;
    for (int i = 1; i < n; i++) {
        edges.push_back({i, i + 1});
    }
    edges.push_back({1, 4});
    edges.push_back({1, 2});
    edges.push_back({2, 3});
    edges.push_back({3, 5});
    edges.push_back({2, 6});
    edges.push_back({6, 7});

    cout << "1 4" << endl;
    cout << "1 2" << endl;
    cout << "2 3" << endl;
    cout << "3 5" << endl;
    cout << "2 6" << endl;
    cout << "6 7" << endl;

    for (int i = 1; i <= 4; i++) {
        for (int j = i + 1; j <= 5; j++) {
            cout << i << " " << j << endl;
        }
    }

    return 0;
}