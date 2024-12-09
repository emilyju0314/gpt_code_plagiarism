#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long count = 0;
    for (int l1 = 0; l1 < n; l1++) {
        for (int r1 = l1; r1 < n; r1++) {
            bool hasLucky1 = false;
            for (int i = l1; i <= r1; i++) {
                if (a[i] == 4 || a[i] == 7) {
                    hasLucky1 = true;
                    break;
                }
            }

            for (int l2 = r1 + 1; l2 < n; l2++) {
                for (int r2 = l2; r2 < n; r2++) {
                    bool hasLucky2 = false;
                    for (int i = l2; i <= r2; i++) {
                        if (a[i] == 4 || a[i] == 7) {
                            hasLucky2 = true;
                            break;
                        }
                    }

                    if (!hasLucky1 && !hasLucky2) {
                        count++;
                    }
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}