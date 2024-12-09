#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    set<int> distinctValues;

    for(int i = 0; i < n; i++) {
        int current = 0;
        for(int j = i; j < n; j++) {
            current |= a[j];
            distinctValues.insert(current);
        }
    }

    cout << distinctValues.size() << endl;

    return 0;
}