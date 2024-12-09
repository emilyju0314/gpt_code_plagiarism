#include <iostream>
#include <vector>

using namespace std;

vector<int> a;
vector<vector<int>> messages;
int n;

bool informStudents(int curr, int cnt) {
    if (cnt == n) {
        return true;
    }

    for (int i = 2; i <= n; i++) {
        if (a[i - 1] > 0 && curr != i) {
            a[i - 1]--;
            messages.push_back({curr, i});
            if (informStudents(i, cnt + 1)) {
                return true;
            }
            a[i - 1]++;
            messages.pop_back();
        }
    }

    return false;
}

int main() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (informStudents(1, 1)) {
        cout << messages.size() << endl;
        for (auto message : messages) {
            cout << message[0] << " " << message[1] << endl;
        }
    } else {
        cout << -1 << endl;
    }

    return 0;
}