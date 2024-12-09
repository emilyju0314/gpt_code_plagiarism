#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> fragments(n);
    for (int i = 0; i < n; i++) {
        cin >> fragments[i];
    }

    string genome = fragments[0];
    for (int i = 1; i < n; i++) {
        string fragment = fragments[i];
        for (char c : fragment) {
            if (genome.find(c) == string::npos) {
                genome += c;
            }
        }
    }

    sort(genome.begin(), genome.end());
    cout << genome << endl;

    return 0;
}