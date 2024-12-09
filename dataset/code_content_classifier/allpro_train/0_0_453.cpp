#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Product {
    long long required_items;
    long long discount_criteria;
};

struct CompareProduct {
    bool operator()(Product const& p1, Product const& p2) {
        return p1.discount_criteria < p2.discount_criteria;
    }
};

int main() {
    int n;
    cin >> n;

    priority_queue<Product, vector<Product>, CompareProduct> pq;

    for (int i = 0; i < n; i++) {
        Product p;
        cin >> p.required_items >> p.discount_criteria;
        pq.push(p);
    }

    long long total_cost = 0;
    long long discount_counter = 0;

    while (!pq.empty()) {
        Product current_product = pq.top();
        pq.pop();

        if (discount_counter < current_product.discount_criteria) {
            total_cost += current_product.required_items * 2;
            discount_counter += current_product.required_items;
        } else {
            total_cost += current_product.required_items;
        }
    }

    cout << total_cost << endl;

    return 0;
}