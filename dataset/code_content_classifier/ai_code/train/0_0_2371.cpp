#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> sequence(n);
    std::unordered_map<int, int> freq;

    for(int i = 0; i < n; i++) {
        std::cin >> sequence[i];
        freq[sequence[i]]++;
    }

    int minFrequency = n;
    for(const auto& entry : freq) {
        if(entry.second < minFrequency) {
            minFrequency = entry.second;
        }
    }

    if(minFrequency == 0) {
        std::cout << -1 << std::endl;
    } else {
        bool allSame = true;
        int operations = 0;
        for(int i = 0; i < n; i++) {
            if(sequence[i] != sequence[k-1]) {
                allSame = false;
                break;
            }
        }
        if(allSame) {
            std::cout << 0 << std::endl;
        } else {
            while(freq[sequence[k-1]] < n) {
                for(int i = 0; i < n; i++) {
                    operations++;
                    if(sequence[i] == sequence[k-1]) {
                        freq[sequence[i]]--;
                        sequence[i] = sequence[k-1];
                        freq[sequence[i]]++;
                        if(freq[sequence[i]] == n) {
                            break;
                        }
                    }
                }
            }
            std::cout << operations << std::endl;
        }
    }

    return 0;
}