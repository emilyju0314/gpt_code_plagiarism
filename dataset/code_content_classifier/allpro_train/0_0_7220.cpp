#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, r1, r2;
    cin >> n >> r1 >> r2;

    vector<int> p(n);
    for (int i = 1; i < n; i++) {
        cin >> p[i];
    }

    for (int i = 1; i <= n; i++) {
        if (i == r2) continue;

        // Find the new path from the capital to city i
        int curr = i;
        vector<int> path;
        while (curr != r1) {
            path.push_back(curr);
            curr = p[curr];
        }

        // Update the representation of the road map
        for (int j = path.size() - 1; j >= 0; j--) {
            cout << path[j] << " ";
        }
    }

    return 0;
}