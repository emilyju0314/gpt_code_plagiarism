#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> rods(n);
    for(int i = 0; i < n; i++) {
        cin >> rods[i];
    }

    sort(rods.begin(), rods.end());

    int sum = 0;
    for(int i = 0; i < n-1; i++) {
        sum += rods[i];
    }

    int additionalLength = max(0, rods[n-1] - sum + 1);

    cout << additionalLength << endl;

    return 0;
}