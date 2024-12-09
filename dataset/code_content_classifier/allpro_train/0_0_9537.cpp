#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> coffees(n);
    for(int i = 0; i < n; i++) {
        cin >> coffees[i];
    }

    sort(coffees.rbegin(), coffees.rend());

    int pages = 0;
    int days = 0;
    while(pages < m) {
        if(coffees.empty() || coffees.back() == 0) {
            cout << -1 << endl;
            return 0;
        }

        pages += max(0, coffees.back() - days);
        coffees.pop_back();
        days++;
    }

    cout << days << endl;

    return 0;
}