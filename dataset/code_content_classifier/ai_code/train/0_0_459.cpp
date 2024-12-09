#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> eggs;
    for (int i = 0; i < n; i++) {
        int a, g;
        cin >> a >> g;
        eggs.push_back(make_pair(a, g));
    }

    int totalA = 0, totalG = 0;
    string result = "";
    for (int i = 0; i < n; i++) {
        if (totalA + eggs[i].first <= totalG + 500) {
            result += "A";
            totalA += eggs[i].first;
        } else {
            result += "G";
            totalG += eggs[i].second;
        }
    }

    if (abs(totalA - totalG) <= 500) {
        cout << result << endl;
    } else {
        cout << "-1" << endl;
    }

    return 0;
}