#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> distinctVarieties;

    for (int i = 1; i <= n; ++i) {
        cout << "? " << i << endl;
        cout.flush();

        char response;
        cin >> response;

        if (response == 'Y') {
            distinctVarieties.push_back(i);
        }
    }

    int d = distinctVarieties.size();

    while (distinctVarieties.size() > 1) {
        cout << "R" << endl;
        cout.flush();

        distinctVarieties.pop_back();
        d--;

        for (int i = 0; i < distinctVarieties.size(); ++i) {
            cout << "? " << distinctVarieties[i] << endl;
            cout.flush();

            char response;
            cin >> response;

            if (response == 'Y') {
                distinctVarieties.erase(distinctVarieties.begin() + i);
                d--;
            }
        }
    }

    cout << "! " << d << endl;
    cout.flush();

    return 0;
}