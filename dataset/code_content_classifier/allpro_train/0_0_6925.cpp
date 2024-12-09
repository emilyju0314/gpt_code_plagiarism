#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int value;
    int weight;
    char type;
    long long date;
    string name;
};

bool compareItems(const Item& a, const Item& b) {
    if (a.value != b.value) {
        return a.value < b.value;
    }
    if (a.weight != b.weight) {
        return a.weight < b.weight;
    }
    if (a.type != b.type) {
        return a.type < b.type;
    }
    if (a.date != b.date) {
        return a.date < b.date;
    }
    return a.name < b.name;
}

int main() {
    int n;
    cin >> n;

    vector<Item> items(n);
    for (int i = 0; i < n; i++) {
        cin >> items[i].value >> items[i].weight >> items[i].type >> items[i].date >> items[i].name;
    }

    sort(items.begin(), items.end(), compareItems);

    for (int i = 0; i < n; i++) {
        cout << items[i].value << " " << items[i].weight << " " << items[i].type << " " << items[i].date << " " << items[i].name << endl;
    }

    return 0;
}