#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int b;
    cin >> b;
    unordered_set<int> happyBoys;
    for (int i = 0; i < b; i++) {
        int boy;
        cin >> boy;
        happyBoys.insert(boy);
    }

    int g;
    cin >> g;
    unordered_set<int> happyGirls;
    for (int i = 0; i < g; i++) {
        int girl;
        cin >> girl;
        happyGirls.insert(girl);
    }

    int day = 0;
    while (true) {
        if (happyBoys.size() == n && happyGirls.size() == m) {
            cout << day << endl;
            break;
        }

        int boy = day % n;
        int girl = day % m;

        if (happyBoys.count(boy) || happyGirls.count(girl)) {
            happyBoys.insert(boy);
            happyGirls.insert(girl);
        }

        day++;

        if (day > 1000000000) {
            cout << -1 << endl;
            break;
        }
    }

    return 0;
}