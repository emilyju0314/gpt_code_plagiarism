#include <iostream>
#include <string>

int main() {
    int n, k, a, b;
    std::cin >> n >> k >> a >> b;

    std::string result = "";

    char curr = a > b ? 'G' : 'B';
    while (a > 0 || b > 0) {
        if (curr == 'G' && a > 0) {
            result += 'G';
            a--;
            if (b > 0) {
                std::swap(a, b);
                curr = curr == 'G' ? 'B' : 'G';
            }
        } else if (curr == 'B' && b > 0) {
            result += 'B';
            b--;
            if (a > 0) {
                std::swap(a, b);
                curr = curr == 'G' ? 'B' : 'G';
            }
        } else {
            result = "NO";
            break;
        }
    }

    std::cout << result << std::endl;

    return 0;
}