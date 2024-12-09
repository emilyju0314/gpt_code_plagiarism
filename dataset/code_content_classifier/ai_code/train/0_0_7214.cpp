#include <iostream>
#include <vector>
#include <algorithm>

struct Problem {
    int resources;
    int scientistNumber;
};

bool compareProblems(const Problem& p1, const Problem& p2) {
    return p1.resources < p2.resources;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<Problem>> scientistProblems(n);

    for (int i = 0; i < n; i++) {
        int ki, ai,1, xi, yi, mi;
        std::cin >> ki >> ai >> xi >> yi >> mi;
        
        for (int j = 0; j < ki; j++) {
            scientistProblems[i].push_back({ ai, i });
            ai = (ai * xi + yi) % mi;
        }
    }

    std::vector<Problem> allProblems;
    for (int i = 0; i < n; i++) {
        for (const Problem& p : scientistProblems[i]) {
            allProblems.push_back(p);
        }
    }

    std::sort(allProblems.begin(), allProblems.end(), compareProblems);

    int badPairs = 0;
    for (int i = 1; i < allProblems.size(); i++) {
        if (allProblems[i].scientistNumber != allProblems[i - 1].scientistNumber) {
            badPairs += allProblems[i].resources < allProblems[i - 1].resources;
        }
    }

    std::cout << badPairs << std::endl;
    for (const Problem& p : allProblems) {
        std::cout << p.resources << " " << p.scientistNumber + 1 << std::endl;
    }

    return 0;
}