#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> sequence(n);
    for(int i = 0; i < n; i++) {
        std::cin >> sequence[i];
    }

    std::vector<int> result;
    for(int i = 0; i < n; i++) {
        if(i < n-1 && sequence[i] == sequence[i+1]) {
            sequence[i]++;
            i++;
        }
        result.push_back(sequence[i]);
    }

    std::cout << result.size() << std::endl;
    for(int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }

    return 0;
}