#include <iostream>
#include <vector>
#include <algorithm>

bool isPrime(int num) {
    if(num < 2) {
        return false;
    }
    for(int i = 2; i * i <= num; i++) {
        if(num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> tiles(n);

    for(int i = 0; i < n; i++) {
        std::cin >> tiles[i].first;
        tiles[i].second = i;
    }

    sort(tiles.begin(), tiles.end());

    std::vector<int> result(n);
    int numOnes = 0;
    int numTwos = 0;

    for(int i = 0; i < n; i++) {
        if(tiles[i].first == 1) {
            if(numOnes * 2 < i) {
                result[tiles[i].second] = 2;
                numTwos++;
            } else {
                result[tiles[i].second] = 1;
                numOnes++;
            }
        } else {
            if(numTwos * 2 < i) {
                result[tiles[i].second] = 1;
                numOnes++;
            } else {
                result[tiles[i].second] = 2;
                numTwos++;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        std::cout << result[i] << " ";
    }

    return 0;
}