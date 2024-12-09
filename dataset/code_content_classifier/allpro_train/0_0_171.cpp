#include <iostream>
#include <vector>
#include <algorithm>

struct Resident {
    std::string name;
    std::string type;
    int bonus;
    std::string home;
};

struct Item {
    std::string name;
    std::string itemClass;
    int atk;
    int def;
    int res;
    int size;
    std::vector<Resident> residents;
};

bool compareItems(const Item& item1, const Item& item2) {
    if (item1.itemClass != item2.itemClass) {
        return item1.itemClass == "weapon";
    } else if (item1.atk != item2.atk) {
        return item1.atk > item2.atk;
    } else if (item1.def != item2.def) {
        return item1.def > item2.def;
    } else {
        return item1.res > item2.res;
    }
}

int main() {
    int n;
    std::cin >> n;

    std::vector<Item> items(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> items[i].name >> items[i].itemClass >> items[i].atk >> items[i].def >> items[i].res >> items[i].size;
    }

    int k;
    std::cin >> k;

    for (int i = 0; i < k; ++i) {
        Resident resident;
        std::cin >> resident.name >> resident.type >> resident.bonus >> resident.home;

        for (Item& item : items) {
            if (item.name == resident.home) {
                item.residents.push_back(resident);
                break;
            }
        }
    }

    std::sort(items.begin(), items.end(), compareItems);

    std::cout << items[0].name << " " << items[0].residents.size() << " ";
    for (const Resident& resident : items[0].residents) {
        std::cout << resident.name << " ";
    }
    std::cout << std::endl;

    std::cout << items[1].name << " " << items[1].residents.size() << " ";
    for (const Resident& resident : items[1].residents) {
        std::cout << resident.name << " ";
    }
    std::cout << std::endl;

    std::cout << items[2].name << " " << items[2].residents.size() << " ";
    for (const Resident& resident : items[2].residents) {
        std::cout << resident.name << " ";
    }
    std::cout << std::endl;

    return 0;
}