#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n;
    
    std::vector<int> team1(n);
    for (int i = 0; i < n; i++) {
        std::cin >> team1[i];
    }
    
    std::cin >> m;
    
    std::vector<int> team2(m);
    for (int i = 0; i < m; i++) {
        std::cin >> team2[i];
    }
    
    std::sort(team1.begin(), team1.end());
    std::sort(team2.begin(), team2.end());
    
    long long maxScore = 0;
    long long score1 = 2 * n;
    long long score2 = 2 * m;
    
    for (int d = 0; d < 2; d++) {
        long long currScore = score1 - score2;
        
        int i = n - 1;
        int j = m - 1;
        
        while (i >= 0 && j >= 0) {
            if (team1[i] - team2[j] > d) {
                currScore += 1;
                i--;
            } else {
                j--;
            }
        }
        
        if (currScore > maxScore) {
            maxScore = currScore;
        }
    }
    
    std::cout << maxScore << ":" << (2 * std::max(n, m) - maxScore) << std::endl;
    
    return 0;
}