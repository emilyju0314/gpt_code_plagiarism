#include <iostream>
#include <vector>
#include <algorithm>

struct Person {
    std::string name;
    int priority = 0;
};

bool compare(const Person &a, const Person &b) {
    if (a.priority != b.priority) {
        return a.priority > b.priority;
    } else {
        return a.name < b.name;
    }
}

int main() {
    std::string myName;
    std::cin >> myName;

    int n;
    std::cin >> n;

    std::vector<Person> people;
    for (int i = 0; i < n; i++) {
        std::string action, verb, target;
        std::cin >> action >> verb >> target;

        if (target != myName) {
            bool found = false;
            for (Person &p : people) {
                if (p.name == target) {
                    found = true;
                    if (verb == "posted") {
                        p.priority += 15;
                    } else if (verb == "commented") {
                        p.priority += 10;
                    } else if (verb == "likes") {
                        p.priority += 5;
                    }
                    break;
                }
            }

            if (!found) {
                Person newPerson;
                newPerson.name = target;
                if (verb == "posted") {
                    newPerson.priority += 15;
                } else if (verb == "commented") {
                    newPerson.priority += 10;
                } else if (verb == "likes") {
                    newPerson.priority += 5;
                }
                people.push_back(newPerson);
            }
        }
    }

    std::sort(people.begin(), people.end(), compare);

    for (const Person &p : people) {
        std::cout << p.name << std::endl;
    }

    return 0;
}