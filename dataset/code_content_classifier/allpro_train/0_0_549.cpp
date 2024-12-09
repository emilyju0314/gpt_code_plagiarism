#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> cards(n);
    for (int i = 0; i < n; i++) {
        std::cin >> cards[i];
    }

    int start = 0, end = n-1;
    int serejaPoints = 0, dimaPoints = 0;

    bool serejaTurn = true;
    while (start <= end) {
        if (cards[start] > cards[end]) {
            if (serejaTurn) {
                serejaPoints += cards[start];
            } else {
                dimaPoints += cards[start];
            }
            start++;
        } else {
            if (serejaTurn) {
                serejaPoints += cards[end];
            } else {
                dimaPoints += cards[end];
            }
            end--;
        }

        serejaTurn = !serejaTurn;
    }

    std::cout << serejaPoints << " " << dimaPoints << std::endl;

    return 0;
}