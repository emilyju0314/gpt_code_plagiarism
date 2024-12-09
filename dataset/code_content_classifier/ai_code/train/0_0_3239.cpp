#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, v;
    cin >> n >> v;
    
    vector<pair<int, int>> trees;
    
    for(int i = 0; i < n; i++) {
        int ai, bi;
        cin >> ai >> bi;
        trees.push_back(make_pair(ai, bi));
    }
    
    sort(trees.begin(), trees.end());
    
    int totalFruits = 0;
    
    for(int day = 1; day <= 3000; day++) {
        int collectedFruits = 0;
        
        for(int i = 0; i < n; i++) {
            if(trees[i].first == day) {
                int fruitsToCollect = min(v, trees[i].second);
                collectedFruits += fruitsToCollect;
                trees[i].second -= fruitsToCollect;
            }
        }
        
        totalFruits += collectedFruits;
        
        for(int i = 0; i < n; i++) {
            if(trees[i].first == day + 1) {
                int fruitsToCollect = min(v - collectedFruits, trees[i].second);
                collectedFruits += fruitsToCollect;
                trees[i].second -= fruitsToCollect;
            }
        }
        
        totalFruits += collectedFruits;
    }
    
    cout << totalFruits << endl;
    
    return 0;
}