#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, h, k;
    
    while (cin >> n >> m >> h >> k) {
        if (n == 0 && m == 0 && h == 0 && k == 0) break;
        
        vector<int> scores(n);
        for (int i = 0; i < n; i++) {
            cin >> scores[i];
        }
        
        vector<pair<int, int>> horizontal_bars(m);
        for (int i = 0; i < m; i++) {
            cin >> horizontal_bars[i].first >> horizontal_bars[i].second;
        }
        
        sort(horizontal_bars.begin(), horizontal_bars.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            return a.second < b.second;
        });
        
        int min_score = 2e9;
        for (int i = 0; i <= n - k; i++) {
            vector<int> selected_scores(scores.begin() + i, scores.begin() + i + k);
            for (int j = 0; j < m; j++) {
                int a = horizontal_bars[j].first;
                int b = horizontal_bars[j].second;
                
                if (a <= i && i+k < a+1) continue;
                
                for (int l = 0; l < k; l++) {
                    if (a == i + l) {
                        swap(selected_scores[l], selected_scores[l+1]);
                        break;
                    }
                }
            }
            
            int sum = 0;
            for (int l = 0; l < k; l++) {
                sum += selected_scores[l];
            }
            
            min_score = min(min_score, sum);
        }
        
        cout << min_score << endl;
    }
    
    return 0;
}