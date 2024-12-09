#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> sticks(n);
    for(int i = 0; i < n; i++) {
        std::cin >> sticks[i];
    }

    std::sort(sticks.begin(), sticks.end());

    int frames = 0;
    for(int i = 0; i < n-1; i++) {
        if(sticks[i] == sticks[i+1]) {
            sticks[i] = -1;
            sticks[i+1] = -1;
            frames++;
        }
    }

    std::cout << frames << std::endl;

    return 0;
}