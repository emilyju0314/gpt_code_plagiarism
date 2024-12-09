#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Scroll {
    int powi;
    int dmgi;
};

bool compareScrolls(Scroll s1, Scroll s2) {
    return s1.powi > s2.powi;
}

int main() {
    int N, max, reg;
    cin >> N >> max >> reg;

    vector<Scroll> scrolls(N);
    for(int i=0; i<N; i++) {
        cin >> scrolls[i].powi >> scrolls[i].dmgi;
    }

    sort(scrolls.begin(), scrolls.end(), compareScrolls);

    int totalDamage = 0;
    for(int i=0; i<N; i++) {
        totalDamage += scrolls[i].dmgi;
    }

    int remainingHealth = max;
    int totalTime = 0;
    vector<pair<int, int>> usedScrolls;

    while(remainingHealth > 0) {
        int currentDamage = 0;
        for(int i=0; i<N; i++) {
            if(scrolls[i].powi <= (100 * remainingHealth / max) && currentDamage + scrolls[i].dmgi <= totalDamage) {
                currentDamage += scrolls[i].dmgi;
                usedScrolls.push_back({totalTime, i+1});
            }
        }
        remainingHealth = max - currentDamage;
        remainingHealth = min(remainingHealth + reg, max);
        totalTime++;
    }

    if(usedScrolls.empty()) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << totalTime << " " << usedScrolls.size() << endl;
        for(auto scroll : usedScrolls) {
            cout << scroll.first << " " << scroll.second << endl;
        }
    }

    return 0;
}