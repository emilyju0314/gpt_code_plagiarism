#include <iostream>
#include <vector>

int main() {
    int m;
    std::cin >> m;

    std::vector<int> sequence;
    for (int i = 0; i < m; i++) {
        int type;
        std::cin >> type;
        
        if (type == 1) {
            int xi;
            std::cin >> xi;
            sequence.push_back(xi);
        } else if (type == 2) {
            int li, ci;
            std::cin >> li >> ci;
            for (int j = 0; j < ci; j++) {
                for (int k = 0; k < li; k++) {
                    sequence.push_back(sequence[k]);
                }
            }
        }
    }

    int n;
    std::cin >> n;

    std::vector<int> interest_sequence;
    for (int i = 0; i < n; i++) {
        int interest_num;
        std::cin >> interest_num;
        interest_sequence.push_back(sequence[interest_num - 1]);
    }

    for (int i = 0; i < n; i++) {
        std::cout << interest_sequence[i] << " ";
    }

    return 0;
}