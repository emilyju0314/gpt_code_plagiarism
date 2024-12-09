#include <iostream>
#include <vector>
#include <algorithm>

struct Card {
    char suit;
    int number;
};

int Partition(std::vector<Card>& A, int p, int r) {
    Card x = A[r];
    int i = p - 1;
    for(int j = p; j < r; j++) {
        if(A[j].number <= x.number) {
            i++;
            std::swap(A[i], A[j]);
        }
    }
    std::swap(A[i+1], A[r]);
    return i + 1;
}

void Quicksort(std::vector<Card>& A, int p, int r) {
    if(p < r) {
        int q = Partition(A, p, r);
        Quicksort(A, p, q - 1);
        Quicksort(A, q + 1, r);
    }
}

int main() {
    int n;
    std::cin >> n;

    std::vector<Card> cards(n);
    for(int i = 0; i < n; i++) {
        std::cin >> cards[i].suit >> cards[i].number;
    }

    std::vector<Card> original = cards;
    Quicksort(cards, 0, n - 1);

    // Check stability
    bool stable = true;
    for(int i = 0; i < n; i++) {
        if(cards[i].number == original[i].number && cards[i].suit != original[i].suit) {
            stable = false;
            break;
        }
    }

    if(stable) {
        std::cout << "Stable" << std::endl;
    } else {
        std::cout << "Not stable" << std::endl;
    }

    for(int i = 0; i < n; i++) {
        std::cout << original[i].suit << " " << original[i].number << std::endl;
    }

    return 0;
}