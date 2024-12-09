#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::string sherlock_card, moriarty_card;
    std::cin >> sherlock_card >> moriarty_card;

    int min_flicks = 0;
    std::vector<int> freq(10, 0);
    for(int i = 0; i < n; i++) {
        freq[sherlock_card[i] - '0']++;
    }

    for(int i = 0; i < n; i++) {
        if(freq[moriarty_card[i] - '0'] > 0) {
            freq[moriarty_card[i] - '0']--;
        } else {
            min_flicks++;
        }
    }

    int max_flicks = 0;
    std::vector<int> sherlock_freq(10, 0);
    std::vector<int> moriarty_freq(10, 0);
    for(int i = 0; i < n; i++) {
        sherlock_freq[sherlock_card[i] - '0']++;
        moriarty_freq[moriarty_card[i] - '0']++;
    }

    for(int i = 0; i < 10; i++) {
        max_flicks += std::max(0, sherlock_freq[i] - moriarty_freq[i]);
    }

    std::cout << min_flicks << std::endl;
    std::cout << max_flicks << std::endl;

    return 0;
}