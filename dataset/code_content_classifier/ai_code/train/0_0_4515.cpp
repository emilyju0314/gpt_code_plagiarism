#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> blue(n-1);
    vector<int> red(n-1);

    for (int i = 0; i < n-1; i++) {
        cin >> blue[i] >> red[i];
    }

    int q;
    cin >> q;

    unordered_map<string, int> state_time;

    int vertex = 1;
    string current_state(n-1, 'B');
    state_time[current_state] = 0;

    for (int i = 0; i < q; i++) {
        int v;
        string s;
        cin >> v >> s;
        
        string initial_state = current_state;
        int time = state_time[initial_state];

        while (true) {
            if (vertex == n) {
                break;
            }

            if (s[vertex-1] == 'R') {
                vertex = red[vertex-1];
            } else {
                vertex = blue[vertex-1];
            }

            if (vertex == v && s == current_state) {
                cout << time << endl;
                break;
            } else if (state_time.find(s) != state_time.end()) {
                cout << -1 << endl;
                break;
            } else {
                current_state = s;
                state_time[current_state] = ++time;
            }
        }

        if (vertex < n) {
            cout << -1 << endl;
        }
    }

    return 0;
}