#include <iostream>
#include <string>
#include <vector>

struct Panel {
    std::string name;
    int x1, y1, x2, y2;
    int numChildren = 0;

    Panel(std::string name, int x1, int y1, int x2, int y2) : name(name), x1(x1), y1(y1), x2(x2), y2(y2) {}
};

int main() {
    int n;
    std::string tagStructure;

    while (std::cin >> n) {
        if (n == 0) break;

        std::cin.ignore(); // Clear newline character
        std::getline(std::cin, tagStructure);

        std::vector<Panel> panels;

        int pos = 0;
        std::string name;
        int x1, y1, x2, y2;

        while (pos < tagStructure.size()) {
            if (tagStructure[pos] == '<') {
                pos++; // Skip '<'
                name = "";
                while (tagStructure[pos] != '>') {
                    name += tagStructure[pos];
                    pos++;
                }
                pos++; // Skip '>'
            } else if (isdigit(tagStructure[pos])) {
                std::string coordinates = "";
                while (tagStructure[pos] != ',') {
                    coordinates += tagStructure[pos];
                    pos++;
                }
                x1 = std::stoi(coordinates);
                pos++; // Skip ','
                coordinates = "";
                while (tagStructure[pos] != ',') {
                    coordinates += tagStructure[pos];
                    pos++;
                }
                y1 = std::stoi(coordinates);
                pos++; // Skip ','
                coordinates = "";
                while (tagStructure[pos] != ',') {
                    coordinates += tagStructure[pos];
                    pos++;
                }
                x2 = std::stoi(coordinates);
                pos++; // Skip ','
                coordinates = "";
                while (tagStructure[pos] != '<' && tagStructure[pos] != '>') {
                    coordinates += tagStructure[pos];
                    pos++;
                }
                y2 = std::stoi(coordinates);

                panels.emplace_back(name, x1, y1, x2, y2);

                pos++; // Skip '<' or '>'
            } else {
                pos++; // Skip any other characters
            }
        }

        for (int i = 0; i < n; i++) {
            int x, y;
            std::cin >> x >> y;
            bool found = false;
            for (int j = panels.size() - 1; j >= 0; j--) {
                if (x >= panels[j].x1 && x <= panels[j].x2 && y >= panels[j].y1 && y <= panels[j].y2) {
                    found = true;
                    std::cout << panels[j].name << " " << panels[j].numChildren << std::endl;
                    break;
                } else {
                    panels[j].numChildren++;
                }
            }
            if (!found) {
                std::cout << "OUT OF MAIN PANEL 1" << std::endl;
            }
        }
    }

    return 0;
}