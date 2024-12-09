#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct CrewMember {
    std::string name;
    std::string status;
};

bool compare(CrewMember a, CrewMember b) {
    if (a.status == "rat" && b.status != "rat") {
        return true;
    } else if ((a.status == "woman" || a.status == "child") && b.status == "man") {
        return true;
    } else {
        return false;
    }
}

int main() {
    int n;
    std::cin >> n;

    std::vector<CrewMember> crew(n);
    for (int i = 0; i < n; i++) {
        std::string name, status;
        std::cin >> name >> status;
        crew[i] = {name, status};
    }

    std::sort(crew.begin(), crew.end(), compare);

    for (int i = 0; i < n; i++) {
        std::cout << crew[i].name << std::endl;
    }

    return 0;
}