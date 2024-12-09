#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n % 2 == 0) {
        cout << 1 << " " << 1 << endl;
        cout.flush();
        int x;
        cin >> x;
    } else {
        vector<int> lamps;
        for (int i = 1; i <= n; i += 2) {
            lamps.push_back(i);
        }

        cout << lamps.size() << " ";
        for (int i = 0; i < lamps.size(); i++) {
            cout << lamps[i] << " ";
        }
        cout << endl;
        cout.flush();

        int x;
        cin >> x;
    }

    cout << 0 << endl;
    cout.flush();

    return 0;
}