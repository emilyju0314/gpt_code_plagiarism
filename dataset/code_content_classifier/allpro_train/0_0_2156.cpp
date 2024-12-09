#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Set {
private:
    set<int> elements;

public:
    Set() {}

    Set(const vector<int>& elems) {
        elements.insert(elems.begin(), elems.end());
    }

    void insert(int elem) {
        elements.insert(elem);
    }

    void remove(int elem) {
        elements.erase(elem);
    }

    Set Union(const Set& other) {
        Set result;
        set_union(elements.begin(), elements.end(), other.elements.begin(), other.elements.end(), inserter(result.elements, result.elements.begin()));
        return result;
    }

    Set Intersection(const Set& other) {
        Set result;
        set_intersection(elements.begin(), elements.end(), other.elements.begin(), other.elements.end(), inserter(result.elements, result.elements.begin()));
        return result;
    }

    Set Difference(const Set& other) {
        Set result;
        set_difference(elements.begin(), elements.end(), other.elements.begin(), other.elements.end(), inserter(result.elements, result.elements.begin()));
        return result;
    }

    Set SymmetricDifference(const Set& other) {
        Set result;
        set_symmetric_difference(elements.begin(), elements.end(), other.elements.begin(), other.elements.end(), inserter(result.elements, result.elements.begin()));
        return result;
    }

    Set Complement(const Set& universe) {
        Set result(universe.elements);
        for (int elem : elements) {
            result.remove(elem);
        }
        return result;
    }

    void Print() {
        for (int elem : elements) {
            cout << elem << " ";
        }
        cout << endl;
    }
};

int main() {
    vector<Set> sets;
    Set universe;

    char setName;
    int numElements;
    while (cin >> setName >> numElements) {
        vector<int> elems(numElements);
        for (int i = 0; i < numElements; i++) {
            cin >> elems[i];
        }
        sort(elems.begin(), elems.end());

        Set newSet(elems);
        sets.push_back(newSet);
        universe = universe.Union(newSet);
    }

    char expressionType;
    int type;
    while (cin >> expressionType >> type) {
        string expression;
        cin >> expression;

        // process the expression and evaluate the result
        // you will need to parse the expression and perform the set operations accordingly
    }

    return 0;
}