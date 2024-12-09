#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    vector<int> order(n);
    for (int i = 0; i < n; ++i) {
        order[i] = i + 1;
    }

    for (int i = 0; i < 2*n; ++i) {
        random_shuffle(order.begin(), order.end());

        cout << "?";
        for (int j = 0; j < n; ++j) {
            cout << " " << order[j];
        }
        cout << endl;

        int k;
        cin >> k;
        if(k != 0) {
            p[k-1] = i+1;
        }
    }

    cout << "! ";
    for (int i = 0; i < n; ++i) {
        cout << p[i] << " ";
    }
    cout << endl;

    return 0;
}