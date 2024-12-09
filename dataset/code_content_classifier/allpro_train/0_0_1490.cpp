#include <iostream>
#include <string>

using namespace std;

int main() {
    string balls;
    cin >> balls;
    
    int ways = 0;
    for (int i = 0; i < balls.size(); i++) {
        int left_color_count = 0, right_color_count = 0;
        char color = balls[i];

        for (int j = i - 1; j >= 0; j--) {
            if (balls[j] == color) {
                left_color_count++;
            } else {
                break;
            }
        }

        for (int j = i + 1; j < balls.size(); j++) {
            if (balls[j] == color) {
                right_color_count++;
            } else {
                break;
            }
        }

        int total_color_count = 1 + left_color_count + right_color_count;
        if (total_color_count >= 3) {
            ways += left_color_count + right_color_count + 1;
        }
    }

    cout << ways << endl;

    return 0;
}