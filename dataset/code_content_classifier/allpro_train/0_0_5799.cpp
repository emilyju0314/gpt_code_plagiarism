#include <iostream>
#include <string>
#include <vector>

struct Card {
    char suit;
    int value;
};

void bubbleSort(std::vector<Card>& cards) {
    int n = cards.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            if (cards[j].value < cards[j - 1].value) {
                std::swap(cards[j], cards[j - 1]);
            }
        }
    }
}

void selectionSort(std::vector<Card>& cards) {
    int n = cards.size();
    for (int i = 0; i < n - 1; i++) {
        int mini = i;
        for (int j = i + 1; j < n; j++) {
            if (cards[j].value < cards[mini].value) {
                mini = j;
            }
        }
        std::swap(cards[i], cards[mini]);
    }
}

int main() {
    int n;
    std::cin >> n;
    
    std::vector<Card> cards(n);
    for (int i = 0; i < n; i++) {
        std::cin >> cards[i].suit >> cards[i].value;
    }
    
    std::vector<Card> bubbleSorted = cards;
    bubbleSort(bubbleSorted);
    
    bool isBubbleStable = true;
    for (int i = 0; i < n; i++) {
        if (bubbleSorted[i].value == bubbleSorted[i + 1].value && bubbleSorted[i].suit > bubbleSorted[i + 1].suit) {
            isBubbleStable = false;
            break;
        }
    }
    
    std::cout << "Bubble Sort Output: ";
    for (int i = 0; i < n; i++) {
        std::cout << bubbleSorted[i].suit << bubbleSorted[i].value << " ";
    }
    std::cout << std::endl;
    
    std::cout << (isBubbleStable ? "Stable" : "Not stable") << std::endl;
    
    std::vector<Card> selectionSorted = cards;
    selectionSort(selectionSorted);
    
    bool isSelectionStable = true;
    for (int i = 0; i < n; i++) {
        if (selectionSorted[i].value == selectionSorted[i + 1].value && selectionSorted[i].suit > selectionSorted[i + 1].suit) {
            isSelectionStable = false;
            break;
        }
    }
    
    std::cout << "Selection Sort Output: ";
    for (int i = 0; i < n; i++) {
        std::cout << selectionSorted[i].suit << selectionSorted[i].value << " ";
    }
    
    std::cout << std::endl;
    
    std::cout << (isSelectionStable ? "Stable" : "Not stable") << std::endl;
    
    return 0;
}