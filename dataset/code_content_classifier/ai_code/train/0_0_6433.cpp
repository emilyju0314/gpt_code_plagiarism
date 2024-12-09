#include <iostream>
#include <vector>
#include <algorithm>

int countInversions(std::vector<std::string> &words) {
    int inversions = 0;
    for (int i = 0; i < words.size(); i++) {
        for (int j = i+1; j < words.size(); j++) {
            if (words[i] > words[j]) {
                inversions++;
            }
        }
    }
    return inversions;
}

bool isSubsequence(std::vector<std::string> &lesha, std::vector<std::string> &archive) {
    int l = 0, r = 0;
    while (l < lesha.size() && r < archive.size()) {
        if (lesha[l] == archive[r]) {
            l++;
        }
        r++;
    }
    return l == lesha.size();
}

int main() {
    int n, m;
    std::cin >> n;
    std::vector<std::string> lesha(n);
    for (int i = 0; i < n; i++) {
        std::cin >> lesha[i];
    }

    std::cin >> m;

    int mostSimilarIndex = -1;
    int minInversions = INT_MAX;

    for (int i = 0; i < m; i++) {
        int k;
        std::cin >> k;
        std::vector<std::string> archive(k);
        for (int j = 0; j < k; j++) {
            std::cin >> archive[j];
        }

        for (int j = 0; j < k - n + 1; j++) {
            std::vector<std::string> subsequence(archive.begin() + j, archive.begin() + j + n);
            int inversions = countInversions(subsequence);
            if (isSubsequence(lesha, subsequence) && inversions < minInversions) {
                minInversions = inversions;
                mostSimilarIndex = i+1;
            }
        }
    }

    if (mostSimilarIndex == -1) {
        std::cout << "Brand new problem!" << std::endl;
    } else {
        std::cout << mostSimilarIndex << std::endl;
        std::cout << "[:";
        for (int i = 0; i < minInversions; i++) {
            std::cout << "|";
        }
        std::cout << ":]" << std::endl;
    }

    return 0;
}