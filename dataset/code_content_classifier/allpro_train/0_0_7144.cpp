#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> orders;
    
    for (int i = 0; i < n; i++) {
        int start, finish;
        cin >> start >> finish;
        orders.push_back(make_pair(start, finish));
    }
    
    sort(orders.begin(), orders.end(), compare);
    
    int accepted = 0;
    int current_end_time = 0;
    
    for (int i = 0; i < n; i++) {
        if (orders[i].first > current_end_time) {
            accepted++;
            current_end_time = orders[i].second;
        }
    }
    
    cout << accepted << endl;
    
    return 0;
}