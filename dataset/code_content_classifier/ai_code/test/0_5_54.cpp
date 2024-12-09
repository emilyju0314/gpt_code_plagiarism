#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        map<int, bool> isImposter; // Map to store if a player is imposter or crewmate
        vector<pair<int, int>> comments; // Vector to store the comments

        bool contradiction = false;

        for (int i = 0; i < m; i++) {
            int a, b;
            string c;
            cin >> a >> b >> c;

            if (c == "imposter") {
                comments.push_back({a, b});
            } else {
                comments.push_back({b, a});
            }

            if (isImposter.find(a) == isImposter.end()) {
                isImposter[a] = false;
            }
            if (isImposter.find(b) == isImposter.end()) {
                isImposter[b] = false;
            }

            if (c == "imposter" && isImposter[b] || c == "crewmate" && !isImposter[b]) {
                isImposter[a] = true;
            }
        }

        for (int i = 0; i < m; i++) {
            int a = comments[i].first;
            int b = comments[i].second;

            if ((isImposter[a] && isImposter[b]) || (!isImposter[a] && !isImposter[b])) {
                contradiction = true;
                break;
            }
        }

        if (contradiction) {
            cout << "-1" << endl;
        } else {
            int impostors = 0;
            for (auto it : isImposter) {
                if (it.second) {
                    impostors++;
                }
            }
            cout << impostors << endl;
        }
    }

    return 0;
}