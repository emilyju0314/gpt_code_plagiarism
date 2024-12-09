#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> tasks(n, vector<int>(3));
    vector<int> attitudes = {0, 0, 0};

    for (int i = 0; i < n; i++) {
        cin >> tasks[i][0] >> tasks[i][1] >> tasks[i][2];
    }

    vector<string> output;
    for (int i = 0; i < n; i++) {
        if (tasks[i][0] > 0 && tasks[i][1] > 0) {
            attitudes[0] += tasks[i][0];
            attitudes[1] += tasks[i][1];
            output.push_back("LM");
        } else if (tasks[i][0] > 0 && tasks[i][2] > 0) {
            attitudes[0] += tasks[i][0];
            attitudes[2] += tasks[i][2];
            output.push_back("LW");
        } else if (tasks[i][1] > 0 && tasks[i][2] > 0) {
            attitudes[1] += tasks[i][1];
            attitudes[2] += tasks[i][2];
            output.push_back("MW");
        } else {
            cout << "Impossible" << endl;
            return 0;
        }
    }

    for (string task : output) {
        cout << task << endl;
    }

    return 0;
}