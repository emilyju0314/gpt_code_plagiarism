#include <iostream>
#include <vector>
#include <string>

struct Button {
    int x1, y1, x2, y2;
    std::string page_link;
};

std::string current_page;
std::vector<std::string> page_history;

void click(std::vector<Button>& buttons, int x, int y) {
    for (Button& button : buttons) {
        if (x >= button.x1 && x <= button.x2 && y >= button.y1 && y <= button.y2) {
            current_page = button.page_link;
            page_history.push_back(current_page);
            break;
        }
    }
}

void back() {
    if (page_history.size() > 1) {
        current_page = page_history[page_history.size() - 2];
        page_history.pop_back();
    }
}

void forward() {
    if (page_history.size() < 2) {
        return;
    }
    current_page = page_history[page_history.size() - 2];
    page_history.pop_back();
}

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        int W, H;
        std::cin >> W >> H;

        std::vector<std::string> pages(n);
        std::vector<std::vector<Button>> buttons_lists(n);

        for (int i = 0; i < n; i++) {
            std::string page_name;
            int num_buttons;
            std::cin >> page_name >> num_buttons;

            pages[i] = page_name;
            std::vector<Button> buttons(num_buttons);
            for (int j = 0; j < num_buttons; j++) {
                int x1, y1, x2, y2;
                std::string page_link;
                std::cin >> x1 >> y1 >> x2 >> y2 >> page_link;
                buttons[j] = {x1, y1, x2, y2, page_link};
            }
            buttons_lists[i] = buttons;
        }

        current_page = pages[0];
        page_history.push_back(current_page);

        int m;
        std::cin >> m;

        for (int k = 0; k < m; k++) {
            std::string operation;
            std::cin >> operation;

            if (operation == "click") {
                int x, y;
                std::cin >> x >> y;
                click(buttons_lists[std::distance(pages.begin(), std::find(pages.begin(), pages.end(), current_page))], x, y);
            } else if (operation == "back") {
                back();
            } else if (operation == "forward") {
                forward();
            } else if (operation == "show") {
                std::cout << current_page << std::endl;
            }
        }
    }

    return 0;
}