#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> balls(n);
    for (int i = 0; i < n; i++) {
        cin >> balls[i];
    }
    
    unordered_map<int, int> frequency;
    for (int ball : balls) {
        frequency[ball]++;
    }
    
    int m;
    cin >> m;
    
    for (int i = 0; i < m; i++) {
        int p;
        cin >> p;
        
        long long totalPairs = 0;
        for (auto it1 = frequency.begin(); it1 != frequency.end(); it1++) {
            for (auto it2 = frequency.begin(); it2 != frequency.end(); it2++) {
                if (it1->first * it2->first >= p) {
                    totalPairs += (long long)it1->second * it2->second;
                }
            }
        }
        
        cout << totalPairs << endl;
    }
    
    return 0;
}