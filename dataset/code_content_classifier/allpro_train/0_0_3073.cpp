#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> lines;
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        lines.push_back({a, b});
        freq[a*a + b*b]++;
    }

    int totalTriangles = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int a1 = lines[i].first, b1 = lines[i].second;
            int a2 = lines[j].first, b2 = lines[j].second;

            int ab = a1*b2 - a2*b1;
            if (ab != 0) {
                totalTriangles += freq[ab];
            }
        }
    }

    cout << totalTriangles << endl;

    return 0;
}