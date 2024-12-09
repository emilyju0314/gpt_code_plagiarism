#include <iostream>
#include <vector>
#include <algorithm>

struct Fox {
    int x;
    int y;
    int w;
};

bool compare(Fox f1, Fox f2) {
    return f1.w > f2.w;
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int n;
    std::cin >> n;

    std::vector<Fox> foxes(n);
    for (int i = 0; i < n; i++) {
        std::cin >> foxes[i].x >> foxes[i].y >> foxes[i].w;
    }

    std::sort(foxes.begin(), foxes.end(), compare);

    int max_foxes = 0;
    int x_diff, y_diff;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int current_foxes = 0;
            for (int k = 0; k < n; k++) {
                if ((foxes[k].x >= foxes[i].x && foxes[k].x <= foxes[j].x) && (foxes[k].y >= foxes[i].y && foxes[k].y <= foxes[j].y)) {
                    current_foxes += foxes[k].w;
                }
            }
            int x_diff_temp = abs(foxes[i].x - foxes[j].x);
            int y_diff_temp = abs(foxes[i].y - foxes[j].y);
            int gcd_temp = gcd(current_foxes, x_diff_temp * y_diff_temp);
            if (current_foxes * max_foxes < max_foxes * x_diff_temp * y_diff_temp) {
                max_foxes = current_foxes;
                x_diff = x_diff_temp / gcd_temp;
                y_diff = y_diff_temp / gcd_temp;
            }
        }
    }

    std::cout << max_foxes << " / " << x_diff * y_diff << std::endl;

    return 0;
}