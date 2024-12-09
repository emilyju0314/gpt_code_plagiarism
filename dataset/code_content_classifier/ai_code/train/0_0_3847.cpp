#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    stack<int> sequence;
    for (int i = 0; i < n; i++) {
        int event;
        cin >> event;

        if (event == 0) {
            sequence.push(0);
        } else if (event == 1) {
            sequence.push(1);
        } else {
            int k = 0;
            for (int j = 0; j < m; j++) {
                if (a[j] <= sequence.size()) {
                    k = a[j];
                } else {
                    break;
                }
            }

            while (k--) {
                sequence.pop();
            }
        }
    }

    if (sequence.empty()) {
        cout << "Poor stack!" << endl;
    } else {
        string result = "";
        while (!sequence.empty()) {
            result += to_string(sequence.top());
            sequence.pop();
        }

        reverse(result.begin(), result.end());
        cout << result << endl;
    }

    return 0;
}