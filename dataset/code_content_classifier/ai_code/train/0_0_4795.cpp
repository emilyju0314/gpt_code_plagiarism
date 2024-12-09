#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    long long cost = 0;
    long long maxId = 0;
    long long currentCost = 0;

    for(int i = 0; i < n; i++) {
        if(a[i] > maxId) {
            cost += currentCost;
            maxId = a[i];
            currentCost = b[i];
        } else {
            currentCost = min(currentCost, b[i]);
        }
    }

    cost += currentCost;

    cout << cost << endl;

    return 0;
}