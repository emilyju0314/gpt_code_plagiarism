#include <iostream>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    int total_data_needed = a * c;
    int data_downloaded_per_second = b;
    int seconds_to_wait = total_data_needed / data_downloaded_per_second;

    if (total_data_needed % data_downloaded_per_second != 0) {
        seconds_to_wait++;
    }

    std::cout << seconds_to_wait << std::endl;

    return 0;
}