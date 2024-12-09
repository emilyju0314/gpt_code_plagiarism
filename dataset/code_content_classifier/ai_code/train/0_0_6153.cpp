#include <iostream>
#include <vector>

using namespace std;

int findGroups(vector<int>& managers, int employee) {
    if (managers[employee] == -1) {
        return 1;
    }
    return 1 + findGroups(managers, managers[employee]);
}

int main() {
    int n;
    cin >> n;

    vector<int> managers(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> managers[i];
    }

    int minGroups = 0;
    for (int i = 1; i <= n; i++) {
        int groups = findGroups(managers, i);
        minGroups = max(minGroups, groups);
    }

    cout << minGroups << endl;

    return 0;
}