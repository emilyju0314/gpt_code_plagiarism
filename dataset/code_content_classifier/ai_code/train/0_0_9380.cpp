#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

const int MOD = 998244353;

int n;
std::vector<std::vector<int>> arrays;
std::vector<int> selected;

bool checkSubset(const std::vector<int>& subset) {
    std::unordered_map<int, int> count;
    
    for (int i = 0; i < subset.size(); i++) {
        for (int j = 0; j < n; j++) {
            count[arrays[subset[i]][j]]++;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (count[i] != n) {
            return false;
        }
    }
    
    return true;
}

void solveTest() {
    std::cin >> n;
    
    arrays.resize(2 * n, std::vector<int>(n));
    
    for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> arrays[i][j];
        }
    }
    
    std::vector<int> indices;
    for (int i = 0; i < 2 * n; i++) {
        indices.push_back(i);
    }
    
    std::vector<bool> possible(1 << (2 * n), false);
    
    do {
        selected.clear();
        for (int i = 0; i < 2 * n; i++) {
            if ((indices[i] >> 1) & 1) {
                selected.push_back(i);
            }
        }
        
        if (selected.size() == n && checkSubset(selected)) {
            possible[indices[0]] = true;
        }
    } while(std::next_permutation(indices.begin(), indices.end()));
    
    int goodSubsets = 0;
    for (int i = 0; i < (1 << (2 * n)); i++) {
        goodSubsets += possible[i];
        if (goodSubsets >= MOD) goodSubsets -= MOD;
    }
    
    std::cout << goodSubsets << std::endl;
    
    for (int i = 0; i < 2 * n; i++) {
        if ((indices[i] >> 1) & 1) {
            std::cout << i + 1 << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    int t;
    std::cin >> t;
    
    while (t--) {
        solveTest();
    }
    
    return 0;
}