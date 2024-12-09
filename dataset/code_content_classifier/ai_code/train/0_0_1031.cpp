#include <iostream>
#include <vector>
#include <string>

void printFormattedPage(int plen, int cnum, int width, int cspace, const std::vector<std::string>& text) {
    int lines = text.size();
    int totalPages = (lines + plen - 1) / plen;

    for (int page = 0; page < totalPages; page++) {
        for (int col = 0; col < cnum; col++) {
            for (int row = 0; row < plen; row++) {
                int index = page * plen + row;
                if (index < lines) {
                    std::string line = text[index];

                    if (line.empty()) {
                        for (int i = 0; i < width; i++) {
                            std::cout << ".";
                        }
                    } else {
                        int remainingWidth = width - line.size();
                        if (remainingWidth > 0) {
                            std::cout << line;
                            for (int i = 0; i < remainingWidth; i++) {
                                std::cout << ".";
                            }
                        } else {
                            int startIndex = 0;
                            while (startIndex < line.size()) {
                                std::string subLine = line.substr(startIndex, width);
                                std::cout << subLine;
                                for (int i = subLine.size(); i < width; i++) {
                                    std::cout << ".";
                                }
                                startIndex += width;
                            }
                        }
                    }

                    if (col < cnum - 1) {
                        for (int i = 0; i < cspace; i++) {
                            std::cout << ".";
                        }
                    }
                }
            }
            std::cout << std::endl;
        }

        if (page < totalPages - 1) {
            for (int i = 0; i < width * cnum + cspace * (cnum - 1); i++) {
                std::cout << "#";
            }
            std::cout << std::endl;
        }
    }
}

int main() {
    int plen, cnum, width, cspace;
    std::string line;
    std::vector<std::string> text;

    while (true) {
        std::cin >> plen;
        if (plen == 0) {
            break;
        }

        std::cin >> cnum >> width >> cspace;

        while (true) {
            std::getline(std::cin, line);
            if (line == "?") {
                break;
            }

            text.push_back(line);
        }

        printFormattedPage(plen, cnum, width, cspace, text);
        std::cout << "?" << std::endl;

        text.clear();
    }

    return 0;
}