#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<int> impostors;

        int first = 1;
        int second = 2;
        int third = 3;

        while (impostors.size() < n/3) {
            cout << "? " << first << " " << second << " " << third << endl;
            int response;
            cin >> response;

            if (response == 0) {
                impostors.push_back(first);
                impostors.push_back(second);
                impostors.push_back(third);
            }

            first += 3;
            second += 3;
            third += 3;
        }

        cout << "! " << impostors.size();
        for (int j = 0; j < impostors.size(); j++) {
            cout << " " << impostors[j];
        }
        cout << endl;
        cout.flush();
    }

    return 0;
}