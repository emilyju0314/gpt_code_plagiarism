#include <iostream>
#include <vector>
#include <algorithm>

long long calculateMaxScore(std::vector<int>& numbers) {
    std::sort(numbers.begin(), numbers.end(), std::greater<int>());
    
    long long score = 0;
    long long sum = 0;
    
    for(int num : numbers) {
        sum += num;
        score += sum;
    }
    
    return score;
}

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> numbers(n);
    
    for(int i = 0; i < n; i++) {
        std::cin >> numbers[i];
    }
    
    long long maxScore = calculateMaxScore(numbers);
    
    std::cout << maxScore << std::endl;
    
    return 0;
}