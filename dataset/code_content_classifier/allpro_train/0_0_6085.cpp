#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ShoePair {
    int price;
    int size;
};

bool compare(ShoePair a, ShoePair b) {
    return a.price < b.price;
}

int main() {
    int n;
    cin >> n;

    vector<ShoePair> pairs(n);
    for(int i=0; i<n; i++) {
        cin >> pairs[i].price >> pairs[i].size;
    }

    sort(pairs.begin(), pairs.end(), compare);

    int m;
    cin >> m;

    vector<pair<int, int>> customers;
    for(int i=0; i<m; i++) {
        int d, l;
        cin >> d >> l;
        customers.push_back({d, l});
    }

    sort(customers.begin(), customers.end());

    int profit = 0;
    int numPairsSold = 0;
    vector<pair<int, int>> pairsSold;

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(pairs[j].size == customers[i].second || pairs[j].size == customers[i].second - 1) {
                if(pairs[j].price <= customers[i].first) {
                    profit += pairs[j].price;
                    numPairsSold++;
                    pairsSold.push_back({i+1, j+1});
                    break;
                }
            }
        }
    }

    cout << profit << endl;
    cout << numPairsSold << endl;
    for(auto p : pairsSold) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}