#include <iostream>
#include <vector>
#include <algorithm>

struct Activity {
    int start_time;
    int finish_time;
};

bool compareActivities(const Activity& a, const Activity& b) {
    return a.finish_time < b.finish_time;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<Activity> activities(n);
    for (int i = 0; i < n; i++) {
        std::cin >> activities[i].start_time >> activities[i].finish_time;
    }

    std::sort(activities.begin(), activities.end(), compareActivities);

    int count = 1;
    int current_end_time = activities[0].finish_time;

    for (int i = 1; i < n; i++) {
        if (activities[i].start_time >= current_end_time) {
            count++;
            current_end_time = activities[i].finish_time;
        }
    }

    std::cout << count << std::endl;

    return 0;
}