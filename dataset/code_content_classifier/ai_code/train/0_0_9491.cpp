#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Biathlete {
    int li, ri, ti, ci;
};

bool compare(Biathlete b1, Biathlete b2) {
    if(b1.ti == b2.ti) {
        return b1.li < b2.li;
    }
    return b1.ti < b2.ti;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Biathlete> biathletes(m);
    map<int, int> bestProfit;

    for(int i = 0; i < m; i++) {
        cin >> biathletes[i].li >> biathletes[i].ri >> biathletes[i].ti >> biathletes[i].ci;
    }

    sort(biathletes.begin(), biathletes.end(), compare);

    int maxProfit = 0;

    for(int i = 1; i <= n; i++) {
        int bestProfitForSection = 0;
        for(int j = 0; j < m; j++) {
            if(biathletes[j].li <= i && biathletes[j].ri >= i) {
                bestProfitForSection = max(bestProfitForSection, bestProfit[i] + biathletes[j].ci);
            }
        }
        bestProfit[i] = bestProfitForSection;
        maxProfit = max(maxProfit, bestProfit[i]);
    }

    cout << maxProfit << endl;

    return 0;
}