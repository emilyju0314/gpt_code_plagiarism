#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPerfectSquare(long long num) {
    long long sqrtNum = sqrt(num);
    return sqrtNum * sqrtNum == num;
}

int main() {
    int n;
    cin >> n;

    vector<int> subset;
    for (int i = 1; i <= n; i++) {
        if (isPerfectSquare(i)) {
            subset.push_back(i);
        }
    }

    cout << subset.size() << endl;
    for (int i = 0; i < subset.size(); i++) {
        cout << subset[i] << " ";
    }
    cout << endl;

    return 0;
}