#include <iostream>
#include <string>
#include <vector>

struct Person {
    std::string name;
    std::string parent;
    std::vector<std::string> children;
};

bool isChildOf(const std::vector<Person>& familyTree, const std::string& child, const std::string& parent) {
    for (const auto& person : familyTree) {
        if (person.name == child && person.parent == parent) {
            return true;
        }
    }
    return false;
}

bool isAncestorOf(const std::vector<Person>& familyTree, const std::string& ancestor, const std::string& descendant) {
    for (const auto& person : familyTree) {
        if (person.name == ancestor) {
            if (isChildOf(familyTree, descendant, person.name)) {
                return true;
            }
            for (const auto& child : person.children) {
                if (isAncestorOf(familyTree, child, descendant)) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool isSiblingOf(const std::vector<Person>& familyTree, const std::string& sibling1, const std::string& sibling2) {
    for (const auto& person : familyTree) {
        if (person.name == sibling1) {
            for (const auto& sibling : person.parent) {
                if (sibling == sibling2) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool isDescendantOf(const std::vector<Person>& familyTree, const std::string& descendant, const std::string& ancestor) {
    return isAncestorOf(familyTree, ancestor, descendant);
}

int main() {
    int n, m;
    while (std::cin >> n >> m && n != 0 && m != 0) {
        std::vector<Person> familyTree;
        for (int i = 0; i < n; ++i) {
            std::string name;
            std::getline(std::cin >> std::ws, name);
            int spaces = 0;
            if (name[0] == ' ') {
                spaces = name.find_first_not_of(' ');
                name = name.substr(spaces);
            }
            Person person{name, "root"};
            if (i > 0) {
                person.parent = familyTree[spaces - 1].name;
                familyTree[spaces - 1].children.push_back(person.name);
            }
            familyTree.push_back(person);
        }

        std::string statement;
        std::getline(std::cin, statement); // Clear newline
        for (int i = 0; i < m; ++i) {
            std::getline(std::cin >> std::ws, statement);
            std::string::size_type isIdx = statement.find(" is ");
            std::string person1 = statement.substr(0, isIdx);
            std::string relation = statement.substr(isIdx + 4);
            std::string person2 = relation.substr(relation.find_last_of(' ') + 1);

            bool result = false;
            if (relation.find("child") != std::string::npos) {
                result = isChildOf(familyTree, person1, person2);
            } else if (relation.find("ancestor") != std::string::npos) {
                result = isAncestorOf(familyTree, person1, person2);
            } else if (relation.find("sibling") != std::string::npos) {
                result = isSiblingOf(familyTree, person1, person2);
            } else if (relation.find("descendant") != std::string::npos) {
                result = isDescendantOf(familyTree, person1, person2);
            }
                
            std::cout << (result ? "True" : "False") << std::endl;
        }

        std::cout << std::endl; // Empty line between data sets
    }

    return 0;
}