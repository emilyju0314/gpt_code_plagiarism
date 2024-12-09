#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    while (cin >> t) {
        if (t == 0) break;
        int n;
        cin >> n;
        int total_time = 0;
        for (int i = 0; i < n; i++) {
            int start, end;
            cin >> start >> end;
            total_time += end - start;
        }
        if (total_time >= t) {
            cout << "OK" << endl;
        } else {
            cout << t - total_time << endl;
        }
    }
    return 0;
}