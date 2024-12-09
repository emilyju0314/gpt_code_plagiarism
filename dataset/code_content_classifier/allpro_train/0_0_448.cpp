#include <iostream>
#include <vector>
#include <algorithm>

struct Person {
    std::string name;
    int a;
};

bool compare(Person p1, Person p2) {
    return p1.a < p2.a;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<Person> people(n);

    for (int i = 0; i < n; i++) {
        std::cin >> people[i].name >> people[i].a;
    }

    std::sort(people.begin(), people.end(), compare);

    std::vector<int> heights(n);

    for (int i = 0; i < n; i++) {
        if (people[i].a > i) {
            std::cout << "-1" << std::endl;
            return 0;
        }
        heights[i] = 1 + i + people[i].a;
    }

    for (int i = 0; i < n; i++) {
        std::cout << people[i].name << " " << heights[i] * 10 << std::endl;
    }

    return 0;
}