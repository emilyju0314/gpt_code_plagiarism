#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> piles(n);
    for(int i = 0; i < n; ++i) {
        int size;
        std::cin >> size;
        piles[i].resize(size);
        for(int j = 0; j < size; ++j) {
            std::cin >> piles[i][j];
        }
    }

    int cielScore = 0, jiroScore = 0;
    bool cielTurn = true;

    int left = 0, right = n - 1;
    while(left <= right) {
        // Ciel's turn
        if(cielTurn) {
            if(piles[left][0] > piles[right][0]) {
                cielScore += piles[left][0];
                piles[left].erase(piles[left].begin());
            } else {
                cielScore += piles[right][0];
                piles[right].erase(piles[right].begin());
            }
        } 
        // Jiro's turn
        else {
            if(piles[left].back() > piles[right].back()) {
                jiroScore += piles[left].back();
                piles[left].pop_back();
            } else {
                jiroScore += piles[right].back();
                piles[right].pop_back();
            }
        }

        // Update turn and left/right pointers
        cielTurn = !cielTurn;
        if(piles[left].empty()) {
            left++;
        }
        if(piles[right].empty()) {
            right--;
        }
    }

    std::cout << cielScore << " " << jiroScore << std::endl;

    return 0;
}