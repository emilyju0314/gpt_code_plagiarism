#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Jewel {
    int x, y;
    long long value;
};

int main() {
    int N, M;
    cin >> N;
    
    vector<Jewel> jewels(N);
    
    for (int i = 0; i < N; i++) {
        cin >> jewels[i].x >> jewels[i].y >> jewels[i].value;
    }
    
    cin >> M;
    
    vector<pair<char, pair<int, int>>> conditions(M);
    
    for (int i = 0; i < M; i++) {
        cin >> conditions[i].first >> conditions[i].second.first >> conditions[i].second.second;
    }
    
    long long max_sum = 0;
    
    for (int bitmask = 0; bitmask < (1 << N); bitmask++) {
        vector<Jewel> stolen_jewels;
        
        for (int i = 0; i < N; i++) {
            if (bitmask & (1 << i)) {
                stolen_jewels.push_back(jewels[i]);
            }
        }
        
        bool valid = true;
        
        for (auto condition : conditions) {
            char t = condition.first;
            int a = condition.second.first;
            int b = condition.second.second;
            
            int count = 0;
            
            if (t == 'L') {
                for (auto jewel : stolen_jewels) {
                    if (jewel.x <= a) {
                        count++;
                    }
                }
            } else if (t == 'R') {
                for (auto jewel : stolen_jewels) {
                    if (jewel.x >= a) {
                        count++;
                    }
                }
            } else if (t == 'U') {
                for (auto jewel : stolen_jewels) {
                    if (jewel.y >= a) {
                        count++;
                    }
                }
            } else if (t == 'D') {
                for (auto jewel : stolen_jewels) {
                    if (jewel.y <= a) {
                        count++;
                    }
                }
            }
            
            if (count > b) {
                valid = false;
                break;
            }
        }
        
        if (valid) {
            long long sum = 0;
            for (auto jewel : stolen_jewels) {
                sum += jewel.value;
            }
            max_sum = max(max_sum, sum);
        }
    }
    
    cout << max_sum << endl;
    
    return 0;
}