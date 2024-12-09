#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> photo(n);
    for (int i = 0; i < n; i++) {
        std::cin >> photo[i];
    }

    // Check if the photo can be a zebra
    bool isZebra = true;
    int prevColor = photo[0];
    int stripeWidth = 1;
    for (int i = 1; i < n; i++) {
        if (photo[i] != prevColor) {
            if (stripeWidth == 1) {
                prevColor = photo[i];
                stripeWidth++;
            } else {
                if (photo[i] == prevColor) {
                    isZebra = false;
                    break;
                }
                stripeWidth = 1;
            }
        } else {
            stripeWidth++;
        }
    }

    if (isZebra) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}