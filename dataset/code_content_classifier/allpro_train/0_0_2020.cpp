#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> bridge_strengths(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> bridge_strengths[i];
    }

    long long points = bridge_strengths[0];
    for (int i = 1; i < n - 1; i++) {
        points += min(bridge_strengths[i], bridge_strengths[i - 1]);
    }

    points += bridge_strengths[n - 2];

    cout << points << endl;

    return 0;
}