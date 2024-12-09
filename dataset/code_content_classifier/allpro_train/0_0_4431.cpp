#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> votes(m, std::vector<int>(n));
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            std::cin >> votes[i][j];
        }
    }

    std::vector<int> sumVotes(n);
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            sumVotes[j] += votes[i][j];
        }
    }

    std::vector<int> sortedVotes = sumVotes;
    std::sort(sortedVotes.begin(), sortedVotes.end(), std::greater<int>());

    int k = 0;
    for(int i = 0; i < n; i++) {
        if(sortedVotes[i] == sumVotes[n-1]) {
            k = i;
            break;
        }
    }

    std::cout << k << std::endl;
    
    for(int i = 0; i < m; i++) {
        bool cancel = false;
        for(int j = 0; j < n; j++) {
            if(i != j && sumVotes[i] <= sumVotes[j]) {
                cancel = true;
                break;
            }
        }
        
        if(cancel) {
            std::cout << i + 1 << " ";
        }
    }
    
    return 0;
}