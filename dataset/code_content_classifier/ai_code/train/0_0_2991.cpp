#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> arr(n);

        int min_pos = 0, max_pos = 0;

        for (int i = 1; i < n; i++) {
            cout << "? " << i << " " << i + 1 << endl;
            fflush(stdout);
            
            string response;
            cin >> response;

            if (response == ">") {
                max_pos = i;
            } else if (response == "<") {
                min_pos = i;
            }
        }

        if (arr[min_pos] == 0) {
            for (int i = 0; i < n; i++) {
                if (i != min_pos) {
                    cout << "? " << min_pos + 1 << " " << i + 1 << endl;
                    fflush(stdout);

                    string response;
                    cin >> response;

                    if (response == ">") {
                        min_pos = i;
                    }
                }
            }
        }

        if (arr[max_pos] == 0) {
            for (int i = 0; i < n; i++) {
                if (i != max_pos) {
                    cout << "? " << max_pos + 1 << " " << i + 1 << endl;
                    fflush(stdout);

                    string response;
                    cin >> response;

                    if (response == "<") {
                        max_pos = i;
                    }
                }
            }
        }

        cout << "! " << min_pos + 1 << " " << max_pos + 1 << endl;
        fflush(stdout);
    }

    return 0;
}