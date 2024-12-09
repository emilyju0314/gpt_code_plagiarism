#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

bool dfs(int idx, int n, int k, std::vector<std::string>& atoms, std::vector<std::string>& target_atoms, std::vector<std::string>& current_atoms, std::vector<std::string>& equations, std::unordered_map<std::string, int>& atomic_numbers) {
    if (idx == k) {
        return true;
    }

    std::string target_atom = target_atoms[idx];
    for (int i = 0; i < n; i++) {
        std::string atom = atoms[i];
        if (current_atoms[i] != "" || atomic_numbers[target_atom] != atomic_numbers[atom]) {
            continue;
        }

        current_atoms[i] = target_atom;
        equations.push_back(atom + "+" + target_atom + "->" + target_atom);
        if (dfs(idx + 1, n, k, atoms, target_atoms, current_atoms, equations, atomic_numbers)) {
            return true;
        }
        current_atoms[i] = "";
        equations.pop_back();
    }
    return false;
}

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<std::string> atoms(n);
    for (int i = 0; i < n; i++) {
        std::cin >> atoms[i];
    }

    std::vector<std::string> target_atoms(k);
    for (int i = 0; i < k; i++) {
        std::cin >> target_atoms[i];
    }

    std::vector<std::string> current_atoms(n, "");
    std::unordered_map<std::string, int> atomic_numbers;
    std::vector<std::string> elements = { "H", "He", ... }; // Complete this list with all elements from the periodic table

    for (int i = 0; i < elements.size(); i++) {
        atomic_numbers[elements[i]] = i + 1;
    }

    std::vector<std::string> equations;

    if (dfs(0, n, k, atoms, target_atoms, current_atoms, equations, atomic_numbers)) {
        std::cout << "YES" << std::endl;
        for (const std::string& equation : equations) {
            std::cout << equation << std::endl;
        }
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}