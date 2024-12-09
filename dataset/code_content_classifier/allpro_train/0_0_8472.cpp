#include <iostream>
#include <vector>

int countCombinations(int n, int s, int start, std::vector<int>& combination) {
    if(n == 0) {
        if(s == 0) {
            return 1;
        } else {
            return 0;
        }
    }

    int count = 0;
    for(int i = start; i <= 9; i++) {
        combination.push_back(i);
        count += countCombinations(n-1, s-i, i+1, combination);
        combination.pop_back();
    }

    return count;
}

int main() {
    int n, s;
    
    while(std::cin >> n >> s) {
        if(n == 0 && s == 0) {
            break;
        }

        std::vector<int> combination;
        int result = countCombinations(n, s, 0, combination);
        std::cout << result << std::endl;
    }

    return 0;
}