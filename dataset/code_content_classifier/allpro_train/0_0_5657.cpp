#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> m1(1, 1);
    vector<int> m2(1, 1);
    map<string, int> paths;

    for (int i = 0; i < n; i++) {
        int t, v;
        char c;
        cin >> t >> v >> c;

        if (t == 1) {
            m1.push_back(m1[v] + 1);
            m2.push_back(m2.back());
        } else {
            m1.push_back(m1.back());
            m2.push_back(m2[v] + 1);
        }

        string forward_path = to_string(m2[v+1]) + " " + to_string(m2.back());
        string backward_path = to_string(m1[v+1]) + " 1";

        paths[forward_path]++;
        int count = paths[backward_path];

        cout << count << endl;
    }

    return 0;
}