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

        // First round of questions
        for (int i = 1; i <= n; i += 3) {
            cout << "? " << i << " " << i + 1 << " " << i + 2 << endl;
            cout.flush();

            int r;
            cin >> r;

            if (r == 0) {
                impostors.push_back(i);
                impostors.push_back(i + 1);
                impostors.push_back(i + 2);
            }
        }

        // Second round of questions
        if (impostors.size() > n / 3) {
            for (int i = 1; i <= n; ++i) {
                if (find(impostors.begin(), impostors.end(), i) == impostors.end()) {
                    cout << "? " << impostors[0] << " " << impostors[1] << " " << i << endl;
                    cout.flush();

                    int r;
                    cin >> r;

                    if (r == 0) {
                        impostors.push_back(i);
                    }
                }
            }
        } else {
            for (int i = 1; i <= n; ++i) {
                if (find(impostors.begin(), impostors.end(), i) == impostors.end()) {
                    cout << "? " << impostors[0] << " " << impostors[1] << " " << i << endl;
                    cout.flush();

                    int r;
                    cin >> r;

                    if (r == 1) {
                        impostors.push_back(i);
                    }
                }
            }
        }

        // Output the result
        cout << "! " << impostors.size() << " ";
        for (int imposter : impostors) {
            cout << imposter << " ";
        }
        cout << endl;
        cout.flush();
    }

    return 0;
}