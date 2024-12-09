#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> impostors;

        for (int i = 1; i <= n; i += 3) {
            cout << "? " << i << " " << i + 1 << " " << i + 2 << endl;
            cout.flush();

            int response;
            cin >> response;

            if (response == 0) {
                impostors.push_back(i);
                impostors.push_back(i + 1);
                impostors.push_back(i + 2);
            } else {
                vector<int> crewmates = {i, i + 1, i + 2};
                do {
                    for (int j : crewmates) {
                        cout << "? " << j << " " << crewmates[0] << " " << crewmates[1] << endl;
                        cout.flush();

                        int response;
                        cin >> response;

                        if (response == 0) {
                            impostors.push_back(j);
                        }
                    }
                } while (next_permutation(crewmates.begin(), crewmates.end()));
            }
        }

        cout << "! " << impostors.size() << " ";
        for (int i : impostors) {
            cout << i << " ";
        }
        cout << endl;
        cout.flush();
    }

    return 0;
}