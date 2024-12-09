#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int calculateNextNumbosome(int n) {
    int nextNumbosome = (3 * n) + 1;
    while (nextNumbosome % 2 == 0) {
        nextNumbosome /= 2;
    }
    return min(nextNumbosome, 12345678);
}

struct Cell {
    int numbosome;
    bool isLeaf;
    bool isLeader;
    vector<Cell*> children;
    Cell* parent;

    Cell(int numbosome, bool isLeaf, bool isLeader) : numbosome(numbosome), isLeaf(isLeaf), isLeader(isLeader) {
        parent = nullptr;
    }

    void addChild(Cell* child) {
        children.push_back(child);
        child->parent = this;
    }
};

void updateLeadership(Cell* cell) {
    if (cell->children.empty()) {
        if (cell->numbosome == 1) {
            if (cell->isLeader) {
                cout << "0 1\n";
                exit(0);
            } else {
                if (cell->parent->children.size() == 1) {
                    cell->parent->children.clear();
                    cell->parent->isLeaf = true;
                }
                cell->parent->children.erase(remove(cell->parent->children.begin(), cell->parent->children.end(), cell), cell->parent->children.end());
            }
            return;
        }
    }

    for (Cell* child : cell->children) {
        updateLeadership(child);
    }

    if (cell->isLeader) {
        int maxNumbosome = 0;
        map<int, Cell*> numbosomeToCell;
        for (Cell* child : cell->children) {
            numbosomeToCell[child->numbosome] = child;
            maxNumbosome = max(maxNumbosome, child->numbosome);
        }

        if (numbosomeToCell.count(maxNumbosome) == 1) {
            int newNumbosome = (maxNumbosome + 1) / 2;
            Cell* newLeader = new Cell(newNumbosome, true, true);
            cell->addChild(newLeader);
        }
    }
}

int main() {
    vector<int> initialNumbosomes;
    int input;
    while (true) {
        cin >> input;
        if (input == 0) {
            break;
        }
        initialNumbosomes.push_back(input);
    }

    for (int initialNumbosome : initialNumbosomes) {
        Cell* root = new Cell(initialNumbosome, true, true);
        updateLeadership(root);
    }

    return 0;
}