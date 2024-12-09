#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> impostors;
        cout << "? 1 2 3" << endl;
        int r1;
        cin >> r1;

        cout << "? 2 3 4" << endl;
        int r2;
        cin >> r2;

        cout << "? 1 2 4" << endl;
        int r3;
        cin >> r3;

        if (r1 != r3) {
            cout << "? 1 3 4" << endl;
            int r4;
            cin >> r4;
            if (r4 != r1) {
                impostors.push_back(2);
                impostors.push_back(3);
                impostors.push_back(4);
            } else {
                impostors.push_back(1);
                impostors.push_back(2);
                impostors.push_back(4);
            }
        } else {
            cout << "? 1 4 3" << endl;
            int r5;
            cin >> r5;
            if (r5 != r1) {
                impostors.push_back(2);
                impostors.push_back(3);
                impostors.push_back(4);
            } else {
                impostors.push_back(1);
                impostors.push_back(2);
                impostors.push_back(3);
            }
        }

        for (int i = 5; i <= n; i += 3) {
            cout << "? " << i << " " << i+1 << " " << i+2 << endl;
            int r;
            cin >> r;
            if (r == 0) {
                impostors.push_back(i);
                impostors.push_back(i+1);
                impostors.push_back(i+2);
            }
        }

        cout << "! " << impostors.size() << " ";
        for (int i = 0; i < impostors.size(); i++) {
            cout << impostors[i] << " ";
        }
        cout << endl;
        cout.flush();
    }

    return 0;
}