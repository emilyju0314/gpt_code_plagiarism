#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> candiesForKids;
    int i = 1;

    while (n > 0) {
        if (n - i >= i + 1) {
            candiesForKids.push_back(i);
            n -= i;
        } else {
            candiesForKids.push_back(n);
            n = 0;
        }
        i++;
    }

    cout << candiesForKids.size() << endl;
    for (int i = 0; i < candiesForKids.size(); i++) {
        cout << candiesForKids[i] << " ";
    }

    return 0;
}