#include <iostream>
#include <vector>

using namespace std;

int countCombinations(vector<pair<int, int>>& cards, int target, int index) {
    if (target == 0) {
        return 1;
    }
    
    if (target < 0 || index == cards.size()) {
        return 0;
    }
    
    int count = 0;
    
    for (int i = 0; i <= cards[index].second; i++) {
        count += countCombinations(cards, target - i * cards[index].first, index + 1);
    }
    
    return count;
}

int main() {
    int m;
    
    while (cin >> m && m != 0) {
        vector<pair<int, int>> cards(m);
        
        for (int i = 0; i < m; i++) {
            cin >> cards[i].first >> cards[i].second;
        }
        
        int g;
        cin >> g;
        
        for (int i = 0; i < g; i++) {
            int n;
            cin >> n;
            
            int count = countCombinations(cards, n, 0);
            
            cout << count << endl;
        }
    }
    
    return 0;
}