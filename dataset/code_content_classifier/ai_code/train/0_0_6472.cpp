#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    int oddReplace = 0, evenReplace = 0;
    std::vector<int> oddFreq(100005, 0), evenFreq(100005, 0);

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            evenFreq[v[i]]++;
        } else {
            oddFreq[v[i]]++;
        }
    }

    int maxEvenFreq = 0, maxOddFreq = 0;
    for (int i = 0; i < 100005; i++) {
        if (evenFreq[i] > maxEvenFreq) {
            maxEvenFreq = evenFreq[i];
        }
        if (oddFreq[i] > maxOddFreq) {
            maxOddFreq = oddFreq[i];
        }
    }

    oddReplace = n / 2 - maxOddFreq;
    evenReplace = n / 2 - maxEvenFreq;

    std::cout << std::min(oddReplace, evenReplace) << std::endl;

    return 0;
}