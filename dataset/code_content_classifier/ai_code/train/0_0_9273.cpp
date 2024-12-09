#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> recolors(n, 0);
    vector<string> niceGarlands = {"RGB", "RBG", "GBR", "GRB", "BRG", "BGR"};

    int minRecolors = n;
    string bestGarland;

    for (auto nice : niceGarlands) {
        int recolorCount = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != nice[i % 3]) {
                recolorCount++;
                recolors[i] = 1;
            }
        }
        if (recolorCount < minRecolors) {
            minRecolors = recolorCount;
            bestGarland = nice;
        }
    }

    cout << minRecolors << endl;
    for (int i = 0; i < n; i++) {
        if (recolors[i] == 1) {
            s[i] = bestGarland[i % 3];
        }
    }
    cout << s << endl;

    return 0;
}