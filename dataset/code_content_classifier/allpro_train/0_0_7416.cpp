#include <iostream>
#include <vector>
#include <stack>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> ages(n);
    for (int i = 0; i < n; i++) {
        std::cin >> ages[i];
    }

    std::vector<int> displeasure(n, -1); // Initialize all displeasure values to -1

    std::stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && ages[i] > ages[st.top()]) {
            displeasure[st.top()] = i - st.top() - 1;
            st.pop();
        }
        st.push(i);
    }

    for (int i = 0; i < n; i++) {
        std::cout << displeasure[i] << " ";
    }

    return 0;
}