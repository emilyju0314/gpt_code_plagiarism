#include <iostream>
#include <unordered_set>
#include <vector>

int main() {
    int n, l, x, y;
    std::cin >> n >> l >> x >> y;

    std::unordered_set<int> marks;
    for(int i = 0; i < n; i++) {
        int mark;
        std::cin >> mark;
        marks.insert(mark);
    }

    std::vector<int> add_marks;
    bool found_x = false, found_y = false;
    for(int mark : marks) {
        if (marks.count(mark + x)) {
            found_x = true;
        }
        if (marks.count(mark + y)) {
            found_y = true;
        }
    }

    if (found_x && found_y) {
        std::cout << 0 << std::endl;
    } else if (found_x || found_y) {
        std::cout << 1 << std::endl;
        if (found_x) {
            std::cout << y << std::endl;
        } else {
            std::cout << x << std::endl;
        }
    } else {
        bool found_sum = false;
        for(int mark : marks) {
            if (marks.count(mark + x + y) || marks.count(mark - x) || marks.count(mark - y)) {
                found_sum = true;
                add_marks.push_back(mark + x);
                break;
            }
        }
        
        if (!found_sum) {
            for(int mark : marks) {
                if (mark + x < l) {
                    add_marks.push_back(mark + x);
                    add_marks.push_back(mark + y);
                    break;
                }
            }
        }

        std::cout << add_marks.size() << std::endl;
        for(int mark : add_marks) {
            std::cout << mark << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}