#include <iostream>
#include <vector>
#include <algorithm>

struct PaintedSection {
    int start;
    int length;
};

bool compareSections(const PaintedSection& s1, const PaintedSection& s2) {
    return s1.length > s2.length;
}

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<PaintedSection> sections(N, {0, 0});

    for (int i = 0; i < M; i++) {
        int start, length;
        std::cin >> start >> length;

        for (int j = start; j < start + length; j++) {
            sections[j % N].length++;
        }
    }

    std::sort(sections.begin(), sections.end(), compareSections);
    
    for (const PaintedSection& section : sections) {
        if (section.length > 0) {
            std::cout << section.length << " " << section.start << std::endl;
        }
    }

    return 0;
}